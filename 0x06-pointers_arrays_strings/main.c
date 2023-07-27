#include <stdio.h>
#include "main.h"

int main(void)
{
    char n1[] = "123";
    char n2[] = "456";
    char result[100];

    char *res = infinite_add(n1, n2, result, 100);
    printf("Result: %s\n", res);

    return 0;
}
