#include "main.h"
#include <stdio.h>

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
	int (*f)(va_list);

	va_start(valist, format);

	if (!format[i + 1] || format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				if (format[i + 1] != 'c' && format[i + 1] != '%' && format[i + 1] != 's'
&& format[i + 1] != 'i' && format[i + 1] != 'd')
				{
					j = j + _putchar(format[i]);
					j = j + _putchar(format[i + 1]);
					i++;
				}
				else
				{
					f = get_op_func(&format[i + 1]);
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
