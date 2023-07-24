#include <stdio.h>
/**
 * swap_int - Swapping variables
 * @a: pointer 1
 * @b: pointer 2
 */
void swap_int(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
} 
