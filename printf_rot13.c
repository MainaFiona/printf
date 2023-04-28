#include "main.h"
#include <ctype.h>
/**
 * printf_rot13 - Prints a ROT13-encoded string.
 * @args: The argument list containing the string to be printed.
 *
 * Return: The total number of characters printed.
 */
int printf_rot13(va_list args)
{
	const char *str = va_arg(args, const char *);
	int i = 0;

	if (str == NULL)
		return -1;

	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
		{
			char base = islower(str[i]) ? 'a' : 'A';
			_putchar((str[i] - base + 13) % 26 + base);
		}
		else
		{
			_putchar(str[i]);
		}
		i++;
	}

	return i;
}

