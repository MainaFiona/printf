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
int print_a_binary(va_list ap);
int print_an_unsigned_int(va_list ap);
int print_an_octa(va_list ap);
int _print_handlers(const char *format, ...);
int _printf_flag(const char *format, ...);
int _printf_0_flag(const char *format, ...);
int _printf_precision(const char *format, ...);
int _printf_rev(const char *format, ...);
int _print_width(const char *format, ...);
int _printf_rot13(const char *format, ...);

#endif /* MAIN_H */
