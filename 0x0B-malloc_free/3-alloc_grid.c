#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - creates  two dimensional array of ints
 * @width: width of the matrix
 * @height: height of the matrix
 *
 * Return: pointer to the created matrix (Success)  or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **arr;
	int i, j;

	if (height <= 0 || width <= 0)
		return (NULL);

	arr = (int **) malloc(height * sizeof(int *));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		arr[i] = (int *) malloc(width * sizeof(int));
	
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}
