#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declarar variable
    string name = GetString();
    
    // Si primera letra es minuscula lo hace mayuscula, si ya lo esta lo imprime
    if (name[0] >= 'a' && name[0] <= 'z')
    {
        printf("%c", name[0] - ('a' - 'A'));    
    }
    else
    {
        printf("%c", name[0]);
    }
    
    // Recorre cada caracter del nombre(s) y busca un espacio    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
    // Encuentra un espacio, convierte la siguiente letra a mayusucla si no esta
        if (name[i] == ' ')
        {
            if (name[i + 1] >= 'a' && name[i + 1] <= 'z')
            {
                printf("%c", name[i + 1] - ('a' - 'A'));
            }
            else
            {
                printf("%c", name[i + 1]);   
            }
        }
    }
    // Imprime espacio
    printf("\n");
}
