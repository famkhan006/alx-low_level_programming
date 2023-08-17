#include "variadic_functions.h"

/**
 * sum_them_all - calculates the sum of all its parameters
 * @n: number of arguments passed to the function
 *
 * Return: the sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int k;
	int sum = 0;
	va_list ls;

	va_start(ls, n);

	for (k = 0; k < n; k++)
		sum += va_arg(ls, int);

	va_end(ls);

	return (sum);
}
