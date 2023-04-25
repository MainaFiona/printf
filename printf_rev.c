#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_string - sets the string to be printed
 * @args: arguments
 * Return: 0
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char*);

	fputs(str, stdout);
}
/**
 * rev_string - function to reverse a string
 * @str: string to be reversed
 * @args:  arguments to be specified
 * Return: str
 */
void rev_string(va_list args)
{
	char *str = va_arg(args, char*);

	int len = strlen(str);

	int i;

	for (i = len - 1; i >= 0; i++)
	{
		fputc(str[i], stdout);
	}
}

/**
 * _print_rev - handles printof a function that
 * prints reverse string
 * @format: formated string to look for
 *
 * Return: count
 */

int _print_rev(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 's':
					print_string(args);
					break;
				case 'r':
					rev_string(args);
					break;
			}
		}
		else
		{
			fputc(*format, stdout);
		}
		format++;
	}
	va_end(args);
	return (0);
}
