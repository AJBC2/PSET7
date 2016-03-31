#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Detectar 2 argumentos y continuar si la cantidad es correcta
    if (argc == 2)
    {
        // Declarar variable del "key" y salir del programa si no es valido
        int k;
        k = atoi(argv[1]);
        if (k < 0)
        {
            printf("Usage: ./Caesar <Caesar>\n");
            return 1;
        }
        // Conseguir la frase
        string text = GetString();
        
        // Recorre cada letra
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Detecta si son letras (pueden ser mayusuclas o minusculas)
            if (islower(text[i]) || isupper(text[i]))
            {
                // Convierte minusculas a mayusculas y viceversa
                if (text[i] >= 'A' && text[i] <= 'Z')
                {
                    printf("%c", (((text[i] - 65) + k) % 26) + 65);
                }
                if (text[i] >= 'a' && text[i] <= 'z')
                {
                    printf("%c", (((text[i] - 97) + k) % 26) + 97);
                }
            }
            // Si es un character que no sea una letra, simplemente lo imprime
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }
    // Si al principio no habia la cantidad correcta de argumentos
    else
    {
        printf("Usage: ./Caesar <Caesar>\n");
        return 1;
    }
}