#include <stddef.h>

char* _memset(char* s, char b, unsigned int n) {
    char* ptr = s; // Keep a reference to the start of the memory area

    // Fill the first n bytes of the memory area with the constant byte b
    for (unsigned int i = 0; i < n; i++) {
        *s = b;
        s++;
    }

    return ptr; // Return the pointer to the memory area s
}
