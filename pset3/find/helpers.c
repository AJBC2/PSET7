/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h> 
#include "helpers.h"

int num = 0;
int nextnum = 0;
    
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int left = 0;
    int right = n - 1;
    int mid = 0;
    
    if (n < 0)
    {
        return false;
    }
    
    do
    {
        mid = (left + right) / 2;
        if (values[mid] < value)
        {
            left = mid + 1;
        }
        
        else if(values[mid] > value)
        {
            right = mid - 1;
        }
        
        else
        {
            return true;
        }
    }    
    while (left <= right);
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = i;
            int num2 = values[i];
        
            if (values[j] < values[num])
            {
                num = j;
            }
    
            if (num != i)
            {
                values[i] = values[num];
                values[num] = num2;   
            }
        
        }
    }    
    return; 
}