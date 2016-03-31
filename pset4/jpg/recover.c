/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEG_SIGNATURE1 0xe0ffd8ff
#define JPEG_SIGNATURE2 0xe1ffd8ff

int main(int argc, char* argv[])
{
    if (argc != 1)
    {
        printf("Usage: Solo un argumento\n");
        return 1;
    }
    
    FILE* file = fopen("card.raw", "r");
    
    if (file == NULL)
    {	
        printf("No se pudo abrir.\n");
        return 1;
	}
    
    int num = 0;
    uint8_t buffer[512];
		
    FILE* out = NULL;
  
    while (fread(buffer, 512, 1, file) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
        && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (out != NULL)
            {
                fclose(out);
            }
            
            char filename[8];
            sprintf(filename,"%03d.jpg", num);
            
            out = fopen(filename, "w");
            num = num + 1;
            
            if (out == NULL) 
            {
                printf("Could not create file.\n");
                return 1;
			}
        }
        
        if (out != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, out);
        }
            
    }
    
    if (out != NULL)
    {
        fclose(out);
    }
    
    fclose(file);
    
    return 0;
}
