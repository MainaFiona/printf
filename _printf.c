#include "main.h"
#include <stdio.h>
#include <stdlib>
#include <stdarg>

/**
 * *get_op_func - function that selects the correct function to perform
 * @s: takes format specifier
 *
 * Return: Always 0.
 */
int (*get_op_func(const char *s))(va_list)
{
	op_t  ops[] = {
		{"c", print_a_char},
		{"s", print_a_str},
		{"%", print_a_pct},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].c)
	{
		if (*s == *(ops[i].c))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 * _printf - function that produces output according to a format
 * @format: takes format specifier
 *
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0;
	int j = 0;

	va_start(valist, format);

	if (!format[i + 1] || format == NULL)
	{
		return (-1);
	}
	while (format[i] != NULL)
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				if (format[i + 1] != 'c' && format[i + 1] != '%' && format[i + 1] != 's')
				{
					j = j + _putchar(format[i + 1]);
					j = j + _putchar(format[i]);
					i++;
				}
				else
				{
					f = get_op_function(&format[i + 1]);
					j = j + f(valist);
					i++;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			j++;
		}
		i++;
	}
	va_end(valist);
	return (j);
}
