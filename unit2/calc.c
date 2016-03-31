#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Como siempre, que detecte que haya una correcta cantidad de arg.
    if (argc == 4)
    {
        // Declarar variables y cambiar a float
        char i = argv[2][0];
        float num = atof(argv[1]);
        float num2 = atof(argv[3]);
        
        // Checa si en la "tercera" posicion hay uno de los siguientes char.
        // Por mala suerte me pasaba por un char, asi que '+' lo converti en PL
        if (i == '+' || i == '-' || i == 'x' || i == '%' || i == '/')
        {
            // Si lo hay, recorre esta parte en busca de que funcion hacer
            if (argv[2][0] == '+')
            {
                float sum = num + num2;
                printf("%f\n", sum);
            }
            if (i == '-')
            {
                float min = num - num2;
                printf("%f\n", min);
            }
            if (i == 'x')
            {
                float mult = num * num2;
                printf("%f\n", mult);
            }
            if (i == '/')
            {
                float div = num / num2;
                printf("%f\n", div);
            }
            if (i == '%')
            {
                float i = floor(num / num2);
                float k = num - (num2 * i);
                printf("%f\n", k);
            }
        }
        // Si no cumplia con uno de los char. termina el programa
        else
        {
            printf("Usage: ./calc <calc>\n");
            return 1;
        }
    }
    // Si desde el principio no habia los arg correctos, se termina
    else
    {
        printf("Usage: ./calc <calc>\n");
        return 1;
    }
}