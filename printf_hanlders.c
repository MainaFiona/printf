#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buff:  array to handle print
 * @flags:  computes active flags.
 * @width: get width.
 * @prec: prec specifier
 * @size: size specifier
 * Return: chars printed.
 */

int handle_write_char(char c, char buff[]
		int flags, int width, int prec, int size)
{ 
	int i = 0;

	char padd = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	bffr++] = c;
	buff[ = '\0';
	if (width > 1)
	{
		bufefBF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			bffrUFF_SIZE - i - 2] = padd;
		if (flags & F_MINU
				return (write(1, &buff[, 1) +
					write(1, &bufefBF_SIZE - i - 1], width - 1));
				else
				return (write(1, &bffrUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[, 1));
				}
				return (write(1, &buff[, 1));
				}


				/**
				 * write_number - prints string
				 * @is_negative: arguments list
				 * @ind: char types.
				 * @buff: uarray to handle print
				 * @flags:  computes active flags
				 * @width: get width.
				 * @prec: prec specifier
				 * @size: size specifier
				 * Return: Number of chars printed.
				 */

int write_number(int is_negative, int ind, char buff[

		int flags, int width, int prec, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buff, flags, width, prec,
				length, padd, extra_ch));
}

/**
 * write_num - puts a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: Buff
 * @flags: Flags
 * @width: width
 * @prec: prec specifier
 * @length:  length
 * @padd: pading char
 * @extra_c: Extra char
 * Return: printed chars.
 */

int write_num(int ind, char buff[],

		int flags, int width, int prec,

		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffind] == '0')
		buff[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buff[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
					write(1, &buff[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], length));
}

/**
 * write_unsgnd - writes an unsigned number
 * @is_negative: indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @prec: prec specifier
 * @size: Size specifier
 * Return:  written chars.
 */

int write_unsgnd(int is_negative, int ind,

		char buff[],

		int flags, int width, int prec, int size)

int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_negative);
UNUSED(size);

if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
return (0);
if (prec > 0 && prec < length)
	padd = ' ';
while (prec > length)
{
	buff[--ind] = '0';
	length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
	padd = '0';
if (width > length)
{
	for (i = 0; i < width - length; i++)
		buff[i] = padd;
	buff[i] = '\0';
	if (flags & F_MINUS)
	{
		return (write(1, &buff[ind], length) + write(1, &buff[0], i));
	}
	else
	{
		return (write(1, &buff[0], i) + write(1, &buff[ind], length));
	}
}
return (write(1, &buff[ind], length));
}

/**
 * write_pointer - writes a memory address
 * @buff: array of chars
 * @ind: where number starts in the buff
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: Number of written chars.
 */

int write_pointer(char buff[], int ind, int length,

		int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], length) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
			buff[--ind] = 'x';
		buff[--ind] = '0';
		if (extra_c)
			buff[--ind] = extra_c;
		return (write(1, &buff[3], i - 3) + write(1, &buff[ind], length));
	}
	else if (!(flags & F_MINUS) && padd == '0')
	{
		if (extra_c)
			buff[--padd_start] = extra_c;
		buff[1] = '0';
		buff[2] = 'x';
		return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], length - (1 - padd_start) - 2));
	}
}
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
	buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
	}

