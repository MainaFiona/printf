#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf_precision - print specified pricision of chars
 * @fmt: the formatted pointer character
 * Return: the precision specified
 */
int _printf_precision(const char fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	char c;

	while ((c = *(fmt++)))
	{
		if (c == '%')
		{
			int precision = 0;

			c = *(fmt++);

			if (c >= '0' && c <= '9')
			{
				precision = precision * 10 + (c - '0');

				c = *(fmt++);
			}
			if (c == 'c')
			{
				char *s = va_arg(args, char*);

				printf("%.*s", precision, s);
			}
			else if (c == 'p')
			{
				voidi *p = va_args(args, void*);

				printf("%.*p", precision, p);
			}
			else if (c == 'n')
			{
				int *n = va_args(args, int*);

				printf("%.n", precision, n);
			}
			else
			{
				_putchar('%');
				if (c)
				{
					_putchar(c);
				}
			}
		}
		else
		{
			_putchar(c);
		}
	}
}
