#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int tot, pow;
	int len;

	if (b == NULL)
		return (0);

	for (pow = 1, tot = 0, len--; len >= 0; len--, pow *= 2)
	{
		if (b[len] == '1')
			tot += pow;
	}

	return (tot);
}
