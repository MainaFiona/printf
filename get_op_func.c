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
		{"s", print_a_str},
		{"%", print_a_pct},
		{"i", print_an_int},
		{"d", print_an_int},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].c)
	{
		if (*s == *(ops[i].c))
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
