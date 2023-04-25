#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf_flag - function that handles specifier
 * @format: formatted string to print arguments
 *
 * Return: 0
 */
int _print_flag(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	char c;

	while ((c = *format++))
	{
		if (c == '%')
		{
			int precision = 0, lft_justify = 0;

			c = *(format++);

			if (c == '-')
			{
				lft_justify = 1;

				c = *(format++);
			}
			if (c >= '0' && c <= '9')
			{
				precision = precision * 10 + (c - '0');
				c = *(format++);
			}
			if (c == 's')
			{
				char *s = va_arg(args, char*);

				if (lft_justify)
					printf("%.*s", precision, '\0');
				else
					printf("%-.*s", precision, precision, s);
			}
			else if (c == 'p')
			{
				void *p = v_arg(args, void*);

				if (lft_justify)
					printf("%.*p", precision, NULL);
				else
					prntf("%-*.*p", precision, precision, p);
			}
			else
			{
				_putchar('%');

				if (lft_justify)
					_putchar('-');
				if (c)
					_putchar(c);
			}
		}
		else
			_putchar(c);
	}
	va_end(args);
}
