#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_an_unsigned_int - function that prints unsigned int
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_an_unsigned_int(va_list ap)
{
	int len = 1;
	int count = 0;
	unsigned int j;
	int i;

	i = va_arg(ap, unsigned int);

	if (i > 0)
	{
		count += _putchar('-');
		j = i * 1;
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
/**
 * print_an_octa - function that prints octal
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_an_octa(va_list ap)
{
	int len = 1;
	int count = 0;
	unsigned int j;
	int i;

	i = va_arg(ap, unsigned int);

	if (i > 0)
	{
		count += _putchar('-');
		j = i * 1;
	}
	else
	{
		j = i;
	}
	while (j / len > 8)
	len *= 8;

	while (len != 0)
	{
		count += _putchar(j / len + '0');
		j %= len;
		len /= 8;
	}
	return (count);
}
