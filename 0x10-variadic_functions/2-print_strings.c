#include "variadic_functions.h"

/**
 * print_strings - prints string
 * @separator: separator b/n  strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int k;
	char *s;

	va_list ls;

	va_start(ls, n);

	for (k = 0; k < n; k++)
	{
		str = va_arg(ls, char *);
		if (!str)
			s = "(nil)";
		if (!separator)
			printf("%s", s);
		else if (separator && k == 0)
			printf("%s", s);
		else
			printf("%s%s", separator, s);
	}

	printf("\n");

	va_end(ls);
}
