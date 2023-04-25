#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - function that handles conversion specifiers
 * @format: string to print formatted args
 *
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i' ||
					*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
			{
				long arg = va_arg(args, long);

				count += printf("%ld", arg);

			}
			else
			{
				count += printf("%%%c", *format);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
