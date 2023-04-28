#include "main.h"
/**
 * printf_flag - function that handles specifier
 * @args: formatted string to print arguments
 *
 * Return: count
 */
int printf_flag(va_list args)
{
	const char *format = va_arg(args, const char *);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			int leftAlign = 0;
			if (*format == '-')
			{
				leftAlign = 1;
				format++;
			}

			if (*format == 'd')
			{
				int value = va_arg(args, int);

				if (leftAlign)
				{
					_putchar('-');
					_putchar('0' + value);
				}
				else
				{
					_putchar('0' + value);
				}
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (leftAlign)
				{
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
					}
				}
				else
				{
					while (*str != '\0')
					{
						_putchar(*str);
						str++;
					}
				}
			}
		}
		else
		{
			_putchar(*format);
		}

		format++;
	}

}
