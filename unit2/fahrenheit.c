#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Si se introduce 2 argumentos (incluyendo C), lo convierte a F y lo imp.
    if (argc == 2)
    {
    // Cambiar el string a float
        float celsius = atof(argv[1]);   
        float fahrenheit = (celsius * 9) / 5 + 32;
        printf("F: %.1f\n", fahrenheit);
    }
    // Rechaza si se introduce menos o mas argumentos
    else
    {
        printf("Usage: ./fahrenheit <fahrenheit>\n");
        return 1;
    }
}    
