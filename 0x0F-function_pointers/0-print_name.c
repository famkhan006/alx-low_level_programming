#include <stdlib.h>
#include "function poinnters.h"

/**
 * print_name - prints name
 * @name: name to print
 * @f: pointer to print name function
 */

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
