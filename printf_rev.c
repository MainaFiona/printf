#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * print_rev - a function that prints reverse string
 * @format: id to llok for 
 *
 * Return: count
 */

int print_rev(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;

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
				char *s = va_arg(args, char *);
				int len = strlen(s);
				for (int i = len - 1; i >= 0; i--)
				{
				_putchar(s[i]);
				count++;
				}
			}
			eslse if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else (*format == 'r')
			{
				char *s = va_arg(args, char *);
				int len = strlen(s);
				for (int i = len - 1; i >= 0; i--)
				{
					char *s = va_arg(args, char *);
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
