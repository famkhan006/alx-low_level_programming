#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program.
 * @ac: Argument count.
 * @av: Pointer to array of size ac.
 *
 * Return: NULL if ac == 0 or av == NULL, Pointer to new string.
 * NULL on fail.
 */
char *argstostr(int ac, char **av)
{
	int i, j, size, idx;
	char *res;

	size = 0;
	idx = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			size++;
			j++;
		}
		size++;
	}

	res = malloc((sizeof(char) * size) + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			res[idx] = av[i][j];
			j++;
			idx++;
		}
		res[idx] = '\n';
		idx++;
	}
	res[idx] = '\0';

	return (res);
}
