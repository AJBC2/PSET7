#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Imprime si hay 2 argumentos
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    // Rechaza si se introduce menos o mas argumentos
    else
    {
        printf("Usage: ./hello <name>\n");
        return 1;
    }
}    