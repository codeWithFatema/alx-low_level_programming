#include "main.h"
#include <stdio.h>

/**
 * infinite_add - add 2 strings.
 * @n1: string1.
 * @n2: string2.
 * @r: buffer
 * @size_r: buffer size
 * Return: String with all letters in ROT13 base.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int a_len = 0, b_len = 0, carry = 0, a, b, sum, biggest;

    while (n1[a_len] != '\0')
        a_len++;
    while (n2[b_len] != '\0')
        b_len++;
    if (a_len > b_len)
        biggest = a_len;
    else
        biggest = b_len;
    if ((biggest + 1) >= size_r)
        return (0);
    r[biggest + 1] = '\0';

    while (biggest >= 0)
    {
        a = (n1[a_len - 1] - '0');
        b = (n2[b_len - 1] - '0');

        if (a_len == 0 && b_len == 0)
            sum = carry;
        else if (a_len == 0)
            sum = b + carry;
        else if (b_len == 0)
            sum = a + carry;
        else
            sum = a + b + carry;

        carry = sum / 10;
        sum = sum % 10 + '0';

        r[biggest] = sum;
        a_len--;
        b_len--;
        biggest--;
    }

    // Check if there's enough space for the carry value
    if (carry > 0 && (biggest + 1) < size_r)
    {
        r[biggest] = carry + '0';
        return r;
    }

    // If carry value cannot be stored, return 0
    return (0);
}
