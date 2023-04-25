#include "main.h"
#include <string.h>
/**
 * rot13_char - function that takes a string as input and returns rot13
 * @c: character to itarate
 * Return: (c)
 */
char rot13_char(char c)
{
	if (isAlpha)
	{
		char base = isUpper(c) ? 'A' : 'a';
		return ((c - base + 13) % 26 + base);
	}
	else
	{
		return (c);
	}
}
/**
 * rot13 - a function that loops through the str
 * @str: string to loop through
 */

void rot13(char *str)
{
	while (*str)
	{
		*str = rot13_char(*str);
		str++;
	}
}
/**
 * _printf_rot13 - handles the conversion specifier for R
 * @format: format string
 *
 * Return: rot13R
 */
int _printf_rot13(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (format + 1) == 'R')
		{
			char *str = va_arg(args, char *);

			rot13(str);
			printf("%s", str);
			format += 2;
		}
		else
		{
			_putchar(*format);
			format++;
		}
	}
	va_end(args);
}
