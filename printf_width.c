#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that prints it
 * @format: pointer to string specifier
 * Return: Always success
 */

int _printf(const char format, ...)
{
	int printed = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format)
		{
			_putchar(*format);
			count++;
			format++;
			continue;
		}
		format++;
		int width = 0;

		while (*format >= '0' && *format <= '9')
		{
			width = width * 10 + (*format - '0');
			format++;
		}
		if (*format == '\0')
		{
			break;
		}
		if (*format == '%')
		{
			_putchar('%');
			count++;
			format++;
			continue;
		}
		if (*format == 'c')
		{
			char val = (char) va_arg(args, int);

			printf("%*c", width, val);
			count += width > 0 ? width : 1;
		}
		else if (*format == 's')
		{
			char *val = va_args(args, char *);

			printf("%*s", width, val);
			count += width > 0 ? width : strlen(val);
		}
		else if (*format == 'd')
		{
			int val = va_arg(args, int);

			printf("%*d", width, val);
			count += width > 0 ? width : 1;
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
