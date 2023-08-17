#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to be searched
 * @size: size of the array
 * @cmp: pointer to the camparision function
 *
 * Return: index of the first comparison element which doesnt
 * return zero , or -1 if no match is found
 * or size is negative
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int k;

	if (array && cmp)
	{
		for (k = 0; k < size; k++)
		{
			if (cmp(array[k]) != 0)
				return (k);
		}
	}

	return (-1);
}
