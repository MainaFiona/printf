#include "main.h"
#include <stdarg.h>

/**
 * _printf_0_flag - function that handles 0 flag
 * @format: character for specified strings
 *
 * Return: format flag
 */

int _printf_0_flag(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '0')
			{
				format++;
			}
			else if (*format == 'd')
			{
				int *d = va_arg(args, int*);

				printf("%d", *d);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				printf("%s", s);
			}
			else
			{
				_putchar('%');
				if (*format != '%')
				{
					_putchar(*format);
				}
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (0);
}
