#include "main.h"
/**
 * printf_flag - function that handles specifier
 * @args: formatted string to print arguments
 *
 * Return: count
 */
int printf_flag(va_list args)
{
	char currentChar;

	int leftAlign = 0;

	int value = va_arg(args, int);

	int formatSpecifier = va_arg(args, int);

	while ((currentChar = va_arg(args, int)) != '\0')
	{

		if (currentChar == '%')
		{

			if (va_arg(args, int) == '-')
			{
				leftAlign = 1;
			}
			if (formatSpecifier == 'd')
			{
				if (leftAlign)
				{
					printf("%-d", value);
				}
				else
				{
					printf("%d", value);
				}
			}
			else if (formatSpecifier == 's')
			{
				char *str = va_arg(args, char *);

				if (leftAlign)
				{
					printf("%s", str);
				}
				else
				{
					printf("%s", str);
				}
			}
		}
		else
		{
			_putchar(currentChar);
		}
	}

	return (leftAlign);
}
