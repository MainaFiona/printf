#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * printf_rot13 - handles the conversion specifier for R
 * @ap: parameters for string
 *
 * Return: rot13R
 */
int printf_rot13(va_list args)
{
	int lgth = 0, x = 0;
       	int l;

	char dep[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnoprstuvwxyz";
	char ariv[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *val = va_arg(args, char *);

	while (val[lgth])
		lgth++;
	if (val == NULL)
	{
		val = "(ahyy)";
	}
	while (val[x] != '\0')
	{
		l = 0;
		while (val[l])
		{
			if (val[x] == dep[l])
			{
				_putchar(ariv[l]);
				break;
			}
			l++;
		}
		x++;
	}
	return (lgth);
}
