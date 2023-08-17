#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - do sth with  a function given as a parameter
 * on each element of an array
 * @array: the array we iterate through
 * @size: size of the array
 * @action: pointer to the function
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int k;

	if (!array || !action)
		return;

	for (k = 0; k < size; k++)
		action(array[k]);
}
