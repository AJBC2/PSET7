#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declarar variables
    int cont = 1;
    int var = 3;
    int height = 0;
    
    // pedir height hasta que no sea negativo
    do 
    {
        printf ("height: ");
        height = GetInt ();
    }
    while (height < 0 || height > 23);
    
    // Loop que se repite basado en el numero de height
    for (int i = 1; i <= height; i = i + 0)
    {
        // espacios
        for (int k = height - 1; k > 0; k--)
        {
            printf(" ");
        }
        // hashes
        for (int j = cont; j < var; j++)
        {
            printf("#");
        }
        // reglas de poner espacios y cuantos hashes
        printf ("\n");
        height = height - 1;
        cont = cont + 1;
        var = (cont * 2) + 1;
    }
}