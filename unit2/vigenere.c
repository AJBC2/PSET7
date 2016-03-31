#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Si hay los argumentos correctos (cantidad)
    if (argc == 2)
    {
        // Variable para la palabra clave
        string key = argv[1];
        
        // Checa cada letra de la clave para detectar chars que no sean letras
        for (int j = 0, k = strlen(key); j < k; j++)
        {
            // Si un char no es letra, termian el programa
            if (!isalpha(key[j]))
            {
                printf("Only alphabetical characters for the word as key");
                return 1;
            }
            // Cambia todos los chars a minuscula
            key[j] = tolower(key[j]);
        }
        
        // Conseguir el texto    
        string text = GetString();
        int k = 0;
            
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Para hacer un "loop"
            int cont = k % strlen(key);
            
            // Si es una letra mayuscula, encriptar
            if (isalpha(text[i]) && isupper(text[i]))
            {
                printf("%c", ((text[i] - 65) + (key[cont] - 97)) % 26 + 65);
                k = k + 1;
            }
            // Si es una letra minuscula, encriptar
            if (isalpha(text[i]) && islower(text[i]))
            {
                printf("%c", ((text[i] - 97) + (key[cont] - 97)) % 26 + 97);
                k = k + 1;
            }
            // Si no es una letra, solo imprimir
            if (!isalpha(text[i]))
            {
                printf("%c", text[i]);
            }
        }        
        printf("\n");
    }
    // Si no habia la cantidad correctos de argumentos
    else
    {
        printf("Usage: ./Vigenere <Vigenere>\n");
        return 1;
    }
}    