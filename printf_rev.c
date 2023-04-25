#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _print_rev - a function that prints reverse string
 * @format: formated string to look for
 *
 * Return: count
 */

int _print_rev(const char *format, ...)
{
	va_list args;

	count = 0;

	int i, len = strlen(s);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				for (i = len - 1; i >= 0; i--)
				{
					_putchar(s[i]);
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'r')
			{
				char *s = va_arg(args, char*);
				
				for (i = len - 1; i >= 0; i--)
				{
					char *s = va_arg(args, char*);

					_putchar(s[i]);
					count++;
				}
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
