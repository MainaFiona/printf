#include "main.h"

/**
 * print_hex_lower - Print hexadecimal number in lowercase
 * @vl: va_list
 * Return: int
 */

int print_hex_lower(va_list vl)
{
	unsigned int num = va_arg(vl, unsigned int);
	int digits = 0, i;
	char hex[16] = "0123456789abcdef";

	if (num == 0)
		return (_putchar('0'));

	while (num != 0)
	{
		digits++;
		num /= 16;
	}

	for (i = digits - 1; i >= 0; i--)
		_putchar(hex[(va_arg(vl, unsigned int) >> (i * 4)) & 0xF]);

	return (digits);
}

/**
 * print_hex_upper - Print hexadecimal number in uppercase
 * @vl: va_list
 * Return: int
 */

int print_hex_upper(va_list vl)
{
	unsigned int num = va_arg(vl, unsigned int);
	int digits = 0, i;
	char hex[16] = "0123456789ABCDEF";

	if (num == 0)
		return (_putchar('0'));

	while (num != 0)
	{
		digits++;
		num /= 16;
	}

	for (i = digits - 1; i >= 0; i--)
		_putchar(hex[(va_arg(vl, unsigned int) >> (i * 4)) & 0xF]);

	return (digits);
}

/**
 * print_hex - Print hexadecimal number
 * @c: unsigned long int
 * @cap: int
 * Return: int
 */

int print_hex(unsigned long int c, int cap)
{
	int digits = 0, i;
	char hex[16];

	if (cap)
	{
		for (i = 0; i < 10; i++)
			hex[i] = i + '0';
		for (; i < 16; i++)
			hex[i] = i - 10 + 'A';
	}
	else
	{
		for (i = 0; i < 10; i++)
			hex[i] = i + '0';
		for (; i < 16; i++)
			hex[i] = i - 10 + 'a';
	}

	if (c == 0)
		return (_putchar('0'));

	while (c != 0)
	{
		digits++;
		c /= 16;
	}

	for (i = digits - 1; i >= 0; i--)
		_putchar(hex[(c >> (i * 4)) & 0xF]);

	return (digits);
}

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
