#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        perror("Error: malloc failed");
        exit(99);
    }

    return (buffer);
}

/**
 * close_file - Closes file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    int c;

    c = close(fd);

    if (c == -1)
    {
        perror("Error: Can't close file descriptor");
        exit(100);
    }
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The num of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer();
    from = open(argv[1], O_RDONLY);
    if (from == -1)
    {
        perror("Error: Can't read from file");
        free(buffer);
        exit(98);
    }

    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to == -1)
    {
        perror("Error: Can't write to file");
        free(buffer);
        exit(99);
    }

    do
    {
        r = read(from, buffer, 1024);
        if (r == -1)
        {
            perror("Error: Can't read from file");
            free(buffer);
            exit(98);
        }

        w = write(to, buffer, r);
        if (w == -1)
        {
            perror("Error: Can't write to file");
            free(buffer);
            exit(99);
        }

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (0);
}
