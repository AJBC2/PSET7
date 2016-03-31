#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // seed PRNG
    srand(time(NULL));
    
    // pick pseudorandom number in [0, 1023]
    int skittles = rand() % 1024;
    
    // Pregunta principal
    printf("The number of skittles is between 0 and 1023.Can you guess it? \n");
    int x = GetInt();
    
    // Creando el Loop
    while (x != skittles) 
    
    {
    // Si el valor que eliges es mas grande que el numero pseudorandom
        if (x > skittles) 
        {
            printf ("It's less than that, try again! \n");
            x = GetInt();
    
    }
    // Si el valor que eliges es mas chico que el numero pseudorandom
        if (x < skittles) 
        {
            printf ("It's bigger than that, try again! \n");
            x = GetInt();

    }
    // Si el valor que eliges es negativo
        if (x < 0) 
        {
            printf ("What are you thinking? Choose another number! \n" );
            x = GetInt();
    
    }
    
    }
    // Lo que aparece una ves que le atinas al numero
    printf ("Woohoo, you guessed it! \n");
  
}
