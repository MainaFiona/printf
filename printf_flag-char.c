#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * printf_flag - function that handles specifier
 * @args: formatted string to print arguments
 *
 * Return: count
 */
int printf_flag(va_list args)
{
	int i = 0, lgt = 0;
	char *s = va_arg(args, char *);
	unsigned int h;
	char nil[] = "(null)";

	if (!s)
	{
		while (nil[i])
		{
			_putchar(nil[i]);
			i++;
		}
		return (i);
	}

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar(92);
			_putchar(120);
			lgt = lgt + 2;
			h = s[i];
			if (h < 16)
			{
				_putchar(48);
				lgt++;
			}
		}
		else
		{
			_putchar(s[i]);
			lgt++;
		}
		i++;
	}

	return (lgt);
}
