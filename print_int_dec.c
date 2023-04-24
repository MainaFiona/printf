#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_an_int - function that prints integer
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_an_int(va_list ap)
{
	int len = 1;
	int count = 0;
	int i, j;

	i = va_arg(ap, int);

	if (i < 0)
	{
		count += _putchar('-');
		j = i * -1;
	}
	else
	{
		j = i;
	}
	while (j / len > 9)
	len *= 10;

	while (len != 0)
	{
		count += _putchar(j / len + '0');
		j %= len;
		len /= 10;
	}
	return (count);
}
