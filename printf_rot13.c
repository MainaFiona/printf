#include "main.h"

/**
 * print_rot13 - a function that prints rot13string
 * @args: list of arguments
 *
 * Return: count
 */

int _printf(const char format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'c')
			{
				int c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'R')
			{
				char *s = va_arg(args, char *);
				while (*s)
				{
					if (*s >= 'a' && *s <= 'z')
					{
						_putchar((*s - 'a' + 15) % 26 + 'a');
					}
					else if (*s >= 'A' && *s <= 'Z')
					{
						_putchar((*s - 'A' + 13) % 26 + 'A');
					}
					else 
					{
						_putchar(*s);
					}
					s++;
					count++;
				}
			}
			else
			{
				_putchar(*format);
				count++;
			}
		}
		va_end(args);
		return (count);
	}
}
