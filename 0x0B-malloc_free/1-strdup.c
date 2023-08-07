#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicates a given string.
 * @src: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string (Success), NULL (Error)
 */
char *_strdup(char *src)
{
    char *duplicate;
    unsigned int i = 0;

    if (src == NULL)
        return NULL;

    while (src[i] != '\0')
        i++;

    duplicate = malloc(sizeof(char) * (i + 1));

    if (duplicate == NULL)
        return NULL;

    i = 0;
    while (src[i] != '\0')
    {
        duplicate[i] = src[i];
        i++;
    }

    duplicate[i] = '\0';

    return duplicate;
}
