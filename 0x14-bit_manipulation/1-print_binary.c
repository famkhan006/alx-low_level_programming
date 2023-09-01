#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		printf("0");
		return;
	}

	unsigned long int temp = n;
	int shifts = 0;

	while (temp > 0)
	{
		temp >>= 1;
		shifts++;
	}

	while (shifts >= 0)
	{
		if ((n >> shifts) & 1)
			printf("1");
		else
			printf("0");

		shifts--;
	}
}
