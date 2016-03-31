/**
 * Andres Joaquin Bolanos Chang - A01154841
 * CS50X - itesm SLP
 * PSET 1-3
 * 18-sep-2015
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // Pedir los datos
    printf("C: ");
    float numero1 = GetFloat();
    
    // Calcular la ecuacion y mostrarla
    float result = ((numero1 * 9) / 5) + 32; 
    printf("F: %.1f\n", result); 
}