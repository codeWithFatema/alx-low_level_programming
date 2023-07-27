#include "main.h"
#include <stdio.h>

/**
 * infinite_add - add 2 strings.
 * @n1: string1.
 * @n2: string2.
 * @r: buffer.
 * @size_r: buffer size.
 * Return: String with the sum of n1 and n2.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int a_len = 0, b_len = 0, carry = 0, a, b, sum, max_len;

    while (n1[a_len] != '\0')
        a_len++;
    while (n2[b_len] != '\0')
        b_len++;

    max_len = (a_len > b_len) ? a_len : b_len;

    if ((a_len + b_len + 1) >= size_r)
        return (0);

    r[max_len + 1] = '\0';

    while (max_len >= 0)
    {
        a = (a_len > 0) ? (n1[a_len - 1] - '0') : 0;
        b = (b_len > 0) ? (n2[b_len - 1] - '0') : 0;

        sum = a + b + carry;
        carry = sum / 10;
        sum = sum % 10 + '0';

        r[max_len] = sum;
        a_len--;
        b_len--;
        max_len--;
    }

    if (*r == '0')
        return (r + 1);
    else
        return (r);
}
