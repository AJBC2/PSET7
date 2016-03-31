#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Declarar muchos variables
    int total = 0;
    int digit = 0;
    int total2 = 0;
    int digit2 = 0;
    
    // Pedir numero. Como estare usando varias versiones del numero, +variables.
    printf("Number: ");
    long long number = GetLongLong ();
    long long number2 = number; 
    long long number3 = number; 
    long long nmb4 = number;
    
    // Que haga el proceso la cantidad de numeros que haya en el numero
    for (int j = 0; j < number3; j = j + 0)
    {
        // Impares
        number = number / 10;
        digit = (number % 10) * 2;
        number = number / 10;
        // Si un impar tiene 2 digitos
        if (digit > 9)
        {
            int newdigit = digit % 10;
            int newdigit2 = digit / 10;
            digit = newdigit + newdigit2;
        }
        total = total + digit;

        // Pares
        digit2 = (number2 % 10);
        number2 = number2 / 100;
            
        total2 = total2 + digit2;
            
        number3 = number3 / 10;
    }
    
    // Para sacar el ultimo digito de todas las sumas juntas y ver si es 0
    int grandtotal = total + total2;
    int ldigit = grandtotal % 10;
    
    // Si el ultimo numero es 0 y cae entre un rango de AMEX, MC o VISA
    if (ldigit == 0 && (nmb4 > pow(10,12) - 1 && nmb4 < pow(10,16)))
    {
        if (floor(nmb4 / pow(10,13)) == 34 || floor(nmb4 / pow(10,13)) == 37)
        {
            printf("AMEX\n");
        }
        if (floor(nmb4 / pow(10,14)) > 50 && floor(nmb4 / pow(10,14)) < 56)
        {
            printf("MASTERCARD\n");
        }
        if (floor(nmb4 / pow(10,12)) == 4 || floor(nmb4 / pow(10,15)) == 4)
        {
            printf("VISA\n");
        }
        
    }    
    // Si no tiene un 0 en el ultimo digito o no cae entre el rango, o ambas
    else
    {
        printf("INVALID\n");
    }
}    
