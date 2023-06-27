#include "main.h"

/***# PRINT POINTER #***/
/**
 * print_pointer - Prints a pointer variable
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Characters printed
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	void *addrs = va_arg(types, void *);
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char c = 0, padd = ' ';
	char map_to[] = "0123456789abcdef";

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)addrs;

	while (num_address > 0)
	{
		buffer[index--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padd, c, padd_start));
}

/***# PRINT NON-PRINTABLE #***/
/**
 * print_non_printable - Prints ascii codes in hexa
 * of non printable characters
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Characters to be printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[b] != '\0')
	{
		if (is_printable(str[b]))
			buffer[b + offset] = str[b];
		else
			offset += append_hexa_code(str[b], buffer, b + offset);

		b++;
	}

	buffer[b + offset] = '\0';

	return (write(1, buffer, b + offset));
}

/***# PRINT REVERSE #***/
/**
 * print_reverse - Prints a string in reverse
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Reversed string of chars
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int s, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (s = 0; str[s]; s++)
		;

	for (s = s - 1; s >= 0; s--)
	{
		char z = str[s];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/***# PRINT A STRING IN ROT13 #***/
/**
 * print_rot13string - Prints a string in rot13.
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of chars (string) in rot13
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char x;
	char *str;
	unsigned int a, b;
	int count = 0;
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
