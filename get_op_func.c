#include "main.h"
#include <stdio.h>

/**
 * *get_op_func - function that selects the correct function to perform
 * @s: takes format specifier
 *
 * Return: Always 0.
 */
int (*get_op_func(const char *s))(va_list)
{
	op_t  ops[] = {
		{"c", print_a_char},
		{"%", print_a_pct},
		{"s", print_a_str},
		{"i", print_an_int},
		{"d", print_an_int},
		{"b", print_a_binary},
		{"u", print_an_unsigned_int},
		{"y", printf_flag},
		{"x", printf_handlers},
		{"r", printf_rev},
		{"R", printf_rot13},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].op != NULL)
	{
		if (*s == *(ops[i].op))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
