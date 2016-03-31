#include <cs50.h>
#include <math.h>
#include <stdio.h>
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(int argc, string argv[])
{
    // Como siempre, que detecte que haya una correcta cant. de arg.
    if (argc == 3)
    {
        // Declarar variables y cambiarlos a int.
        int days;
        days = atoi(argv[1]);
        int pennies; 
        pennies = atoi(argv[2]);
        
        // Rechaza dias fuera del rango y pennies negativos
        if (days < MIN_DAYS || days > MAX_DAYS || pennies < 0)
        {
            printf("Usage: ./pennies <pennies>\n"); 
            return 1;
        }
        long long total = pennies;
    
        // Calcula e imprime resultados
        for(int i = 1; i < days; i++)
        {
            total += pennies * pow(2,i);
        }
        
        printf("$%.2f\n", ((double) total) / 100);
    }
    // Rechaza si se introduce menos o mas argumentos
    else
    {
        printf("Usage: ./pennies <pennies>\n");
        return 1;
    }
}