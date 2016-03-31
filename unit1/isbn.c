#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declarar variables
    long long isbn = 0;
    int digit = 0;
    int total = 0;
    
    // te pide e; ISBN
    printf("ISBN: ");
    isbn = GetLongLong ();
    
    // Multiplica el ultimo digito por diez, penultimo por 9, etc. y los suma
    for (int i = 10; i > -1; i--)
    {
        digit = isbn % 10;
        isbn = isbn / 10;
        total = total + (digit * i);
    }
    // Para sacar el residuo
    total = total % 11;
    
    // si el residuo es 0
    if (total == 0)
    {
        printf ("YES\n");
    }
    
    // si el resiudo no es 0 
    else
    {
        printf ("NO\n");
    }
}