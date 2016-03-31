#define _XOPEN_SOURCE
#define LIMIT 65536
#include <cs50.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checa si no hay 3 o 4 argumentos (los necesarios), y se sale
    if (argc < 3 || argc > 4)
    {
        printf("Usage: ./rng <rng>\n");
        return 1;
    }    
    
    // declarar el valor maximo y el srand48 con tiempo si solo hay 3 argumentos
    int max = 0;
    max = atoi(argv[2]);
    srand48(time(NULL));
    
    // Si hay 4 argumentos, srand48 sera con tu valor del seed
    if (argc == 4)
    {
        int seed = 0;
        seed = atoi(argv[3]);
        // Seed tiene que ser un valor mayor a 0
        if (seed > 0)
        {
            srand48(seed);
        }
        else
        {
            printf("Usage: ./rng <rng>\n");
            return 1;
        }
    }
    
    // Termina el programa si el max es menor/igual que cero o mayor que LIMIT
    if (max <= 0 || max > LIMIT)
    {
        printf("Usage: ./rng <rng>\n");
        return 1;
    }
    
    // Declarar el variable n, para decir cuantos numeros quieres    
    int n = 0;
    n = atoi(argv[1]);
    
    // Si n es mayor que 0, imprimira los numeros usando un loop for    
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            float i = drand48() * max;
            printf("%.0f\n", i);
        }
    }
    // Si n es menor a 0
    else
    {
        printf("Usage: ./rng <rng>\n");
        return 1;
    }
}    
