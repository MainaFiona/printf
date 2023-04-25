#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf_precision - print specified pricision of chars
 * @fmt: the formatted pointer character
 * Return: the precision specified
 */
int _printf_precision(const char *fmt, ...)
{
	char c;

	va_list args;

	va_start(args, fmt);

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
				void *p = va_arg(args, void*);

				printf("%.*p", precision, p);
			}
			else if (c == 'n')
			{
				int *n = va_arg(args, int*);

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
			c++;
		}
	}
	va_end(args);
	return (c);
}
