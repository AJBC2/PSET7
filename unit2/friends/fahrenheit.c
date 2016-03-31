#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // get celsius from user
    printf("C: ");
    float celsius = GetFloat();
    
    // convert to fahrenheit; no float errors b/c celsius is a float
    float fahrenheit = (celsius * 9) / 5 + 32;
    printf("F: %.1f\n", fahrenheit);
}