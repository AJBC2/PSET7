#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // variables
    double todo = 0;
    double cuadrado = 0;
    double resultado = 0;
    int contador = 0;
    
    // conseguir dias del mes
    printf("Days in month: ");
    int days = GetInt ();
    
    // los dias tienen que ser entre 28 y 31
    while (days > 31 || days < 28)
    {
        printf("Days in month: ");
        days = GetInt ();
    }
 
    // pedir las monedas
    printf("Pennies on first day: ");
    int pennies = GetInt ();
    
   // no puede ser negativo
    while (pennies <= 0)
    {
        printf("Pennies on first day: ");
        pennies = GetInt ();
    }
    
   // saca el valor de los pennies
    while (contador < days)
    {
        cuadrado = pennies * (pow(2,contador));
        todo = todo + cuadrado;
        contador = contador + 1;
    }
    
    resultado = todo / 100;
    
    // lo imprime
    printf ("$%.2f \n", resultado);
    
}
