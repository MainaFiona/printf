#include <stdarg.h>
#include <stdio.h>
/**
 * print_binary - writes in binary
 * @args: The va_list containing the arguments
 *
 * Return: On success, the length.
 */
int print_binary(va_list args)
{
    unsigned int value = va_arg(args, unsigned int);
    int count = 0;
    int binary[32];

    for (int i = 0; i < 32; i++) {
        binary[i] = value % 2;
        value /= 2;
    }

    int start_printing = 0;
    for (int i = 31; i >= 0; i--) {
        if (binary[i] || start_printing) {
            putchar('0' + binary[i]);
            count++;
            start_printing = 1;
        }
    }

    return count;
}
