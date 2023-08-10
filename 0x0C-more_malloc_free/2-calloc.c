#include <stdlib.h>
#include "main.h"

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	int n = nmemb * size;

	ptr = malloc(n);

	if (ptr == NULL)
		return (NULL);
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = 0;
	}

	return (ptr);

}
