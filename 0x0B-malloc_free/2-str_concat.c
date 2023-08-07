#include <stdlib.h>
#include "main.h"

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *c;
	unsigned int i = 0, j = 0, length1 = 0, length2 = 0;

	while (s1 && s1[length1])
		length1++;
	while (s2 && s2[length2])
		length2++;

	c = malloc(sizeof(char) * (length1 + length2 + 1));
	if (c == NULL)
		return (NULL);

	if (s1)
	{
		while (i < length1)
		{
			c[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (length1 + length2))
		{
			c[i] = s2[j];
			i++;
			j++;
		}
	}
	c[i] = '\0';

	return (c);
}
