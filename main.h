#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct op - Struct op
 *
 * @c: format specifier
 * @f: The function associated
 */
typedef struct op
{
	char *c;
	int (*f)(va_list);
} op_t;

int _putchar(char c);
int (*get_op_func(const char *s))(va_list);
int _printf(const char *format, ...);
int print_a_char(va_list ap);
int print_a_str(va_list ap);
int print_a_pct(va_list ap);
int print_an_int(va_list ap);
int print_a_dec(va_list ap);
int print_an_unsigned_int(va_list ap);
int print_an_octa(va_list ap);
int print_a_binary(va_list ap);

#endif /* MAIN_H */
