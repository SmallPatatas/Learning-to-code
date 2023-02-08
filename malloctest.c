#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int size = 10;
    char *malloc_it = malloc(size);
    for (int i = 0; i < size - 5; i++)
    {
        malloc_it[i] = 'A';
    }
    malloc_it[size - 5] = '\0';

    printf("counting to your number - 5: %s!\n", malloc_it);
    free(malloc_it);
    return 0;
}