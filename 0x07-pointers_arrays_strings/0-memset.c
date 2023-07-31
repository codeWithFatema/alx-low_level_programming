#include<stdio.h>
#include<string.h>
char* _memset(char* s, char b, unsigned int n);
int main(){
char buffer[10]; //creates a buffer of size 10 bytes 
    char* result;
    // Fill the buffer with the constant byte 'A' (ASCII value 65)
    result = _memset(buffer, 'A', 10);
    // Print the buffer to check the result
    for (int i = 0; i < 10; i++) {
        printf("%c ", buffer[i]);
    }
    return 0;
}
