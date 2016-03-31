#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // variables usadas
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    
    // Pedir cuanto cambio se necesita
    printf("How much change is owed? \n");
    float change = GetFloat ();
    
   // Preguntara hasta que el usuario introduzca un valor no negativo
    while (change < 0) 
    {
        printf("How much change is owed? \n");
        change = GetFloat ();
    }
    
    // Esta es la parte donde se redondea y se convierte a centavos
    change = change * 100;
    change = round(change);
    
    // De aqui, suma todas las monedas que necesita de cada una
    if (change / 25 > 0) 
    {
        int result2 = floor(change / 25);
        contador1 = result2;
        change = change - (25 * result2);
    }
    if (change / 10 > 0) 
    {
        int result3 = floor(change / 10);
        contador2 = result3;
        change = change - (10 * result3);
    }
    if (change / 5 > 0) 
    {
        int result4 = floor(change / 5);
        contador3 = result4;
        change = change - (5 * result4);
    }
    if (change / 1 > 0) 
    {
        int result5 = floor(change / 1);
        contador4 = result5;
        change = change - (1 * result5);
        }
    
    // Muestra resultados de cuantas monedas se necesitaran
    printf ("%d\n", contador1 + contador2 + contador3 + contador4);
}