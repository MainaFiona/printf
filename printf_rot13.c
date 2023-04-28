#include "main.h"
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
	return c;
}

/**
 * print_rot13 - Prints a string with ROT13-encoded characters.
 * @str: The input string to be printed.
 *
 * Return: The total number of characters printed.
 */
int _printf_rot13(const char *str, ...)
{
	int count = 0;

	for (; *str; str++)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'R')
			{
				str += 2;
				for (; *str && *str != '%'; str++)
				{
					putchar(rot13(*str));
					count++;
				}
				str--;
			}
			else
			{
				putchar(*str);
				count++;
			}
		}
		else
		{
			putchar(*str);
			count++;
		}
	}
	return count;
}

