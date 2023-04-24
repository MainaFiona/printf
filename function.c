#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_a_char - function that prints character
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_a_char(va_list ap)
{
	int c;

	c = va_arg(ap, int);
	_putchar(c);
	return (1);
}
/**
 * print_a_pct - function that prints percentage
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_a_pct(va_list ap)
{
	(void)ap;
	return (write(1, "%", 1));
}
/**
 * print_a_str - function that prints string
 * @ap: list of variadic
 * Return: Always 0.
 */
int print_a_str(va_list ap)
{
	int i;
	char *str = va_arg(ap, char *);

	if (str == NULL)
	{
		str = "(nil)";
	}
	for (i = 0; str[i]; i++)
	{

		_putchar(str[i]);
	}
	return (i);
}
