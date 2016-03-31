// includes
#include <cs50.h>
#include <math.h>
#include <stdio.h>

// defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(void)
{
    // get a number of days in [28, 31]
    int days;
    do
    {
        printf("Days in month: ");
        days = GetInt();
    }
    while(days < MIN_DAYS || days > MAX_DAYS);
    
    // get a number of pennies in [0, inf)
    int pennies;
    do
    {
        printf("Pennies on first day: ");
        pennies = GetInt();
    }
    while(pennies <= 0);
    
    // relatively few pennies required to get out of bounds of int
    long long total = pennies;
    
    // add double the amount of pennies of the previous day each day
    for(int i = 1; i < days; i++)
    {
        total += pennies * pow(2,i);
    }
        
    // output the total as dollars and cents only
    printf("$%.2f\n", ((double) total) / 100);
}