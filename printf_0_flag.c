#include "main.h"
#include <stdarg.h>

/**
 * _printf_flag - function that handles 0 flag
 * @format: character for specified strings
 *
 * Return: format flag
 */

int _printf_flag(const char *format, ...)
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
				void *d = va_arg(args, void*);

				printf("%d", d);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				printf("%s", s);
			}
			else
			{
				putchar('%');
				if (*format != '%')
				{
					putchar(*format);
				}
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
