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
	int num;
	int len = 0;
	int i = 1;

	num = va_arg(ap, int);

	if (num < 0)
	{
		_putchar('-');
		num *= -1;
		len++;
	}
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	i = 10;

	while (i <= num)
	{
		i *= 10;
	}
	i = 10;

	while (i > 0)
	{
		_putchar(((num / i) % 10) + '0');
		i /= 10;
		len++;
	}
	return (len);
}
