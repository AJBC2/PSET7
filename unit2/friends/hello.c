#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // collect a string from the user, then print their name
    printf("Your name: ");
    string name = GetString();
    printf("hello, %s\n", name);
}