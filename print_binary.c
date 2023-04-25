#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_an_unsigned_int - function that prints unsigned int
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_a_binary(va_list ap)
{
	int len = 1;
	int count = 0;
	unsigned int j;
	int i;

	i = va_arg(ap, unsigned int);

	if (i < 0)
	{
		count += _putchar('-');
		j = i * -1;
	}
	else
	{
		j = i;
	}
	while (j / len > 2)
	len *= 2;

	while (len != 0)
	{
		count += _putchar(j / len + '0');
		j %= len;
		len /= 2;
	}
	return (count);
}
