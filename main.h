#ifndef MAIN-H
#define MAIN_H
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
    char *c;
    int (*f)(va_list);
} op_t;

int _putchar(char c);
int (*get_op_func(const char *s))(va_list)
int print_a_char(va_list ap);
int print_a_str(va_list ap);
int print_a_pct(va_list ap);

/* SIZES */
#define S_LONG 2
#define S_short 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#endif /* MAIN_H */
