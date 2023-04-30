#include <stdarg.h>
#include "main.h"

/**
 * print_a_binary - writes an unsigned int in binary format
 * @ap: The va_list containing the argument
 *
 * Return: The number of characters printed
 */
int print_a_binary(va_list *ap)
{
    unsigned int val = va_arg(*ap, unsigned int);

    int len = 0;

    if (val == 0)
    {
        _putchar('0');
        return 1;
    }

    while (val)
    {
        len++;
        _putchar((val & 1) + '0');
        val >>= 1;
    }

    return (len);
}


