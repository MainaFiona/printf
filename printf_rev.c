#include "main.h"
/**
 * print_string - sets the string to be printed
 * @len: length of string to calculate
 * Return: 0
 */
int print_string(char *t, int len)
{
	if (t[0] != '\0')
	{
		len = print_string(t + 1, len + 1);
		_putchar(t[0]);
	}
	return (len);
}

/**`
 * _print_rev - handles printof a function that
 * prints reverse string
 * @format: formated string to look for
 *
 * Return: count
 */

int print_rev(va_list *parms)
{
	int len = 0; 
	char *stlen = va_arg(*parms, char *);

	if(stlen == NULL)
		stlen = "(llun)";
	return (print_string(stlen, len));

}
