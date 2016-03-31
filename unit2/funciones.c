/**
 * Andres Joaquin Bolanos Chang - A01154841
 * CS50X - itesm SLP
 * PSET 1-3
 * 18-sep-2015
 */
 
#include <stdio.h>
#include <cs50.h>

//prototype
void PrintName(string name);

int main(void)
{
    printf("Your name: ");
    string s = GetString();
    PrintName(s);
}

void PrintName(string name)
{
    printf("hello, %s\n", name);
}