#include "main.h"
#include <ctype.h>

/**
 * rot13 - Applies the ROT13 cipher to a character.
 * @c: The character to be encoded.
 *
 * Return: The ROT13-encoded character.
 */
char rot13(char c)
{
	if (isalpha(c))
	{
		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
			c += 13;
		else
			c -= 13;
	}
	return (c);
}

/**
 * printf_rot13 - Prints a ROT13-encoded string.
 * @args: The argument list containing the string to be printed.
 *
 * Return: The total number of characters printed.
 */
int printf_rot13(va_list args)
{
	int count = 0;
	const char *str = va_arg(args, const char *);

	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'R')
		{
			str += 2;

			while (*str && *str != '%')
			{
				_putchar(rot13(*str));
				count++;
				str++;
			}
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}

	return (count);
}

