#include "main.h"

/***# PRINT UNSIGNED NUMBERS #***/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Elements printed of type int
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[x--] = (numb % 10) + '0';
		numb /= 10;
	}

	x++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***# PRINT UNSIGNED NUMBERS IN OCTAL #***/
/**
 * print_octal - Prints unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Values of type int
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int N = num;
	unsigned long int num = va_arg(types, unsigned long int);

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && N != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***# PRINT UNSIGNED NUMBER IN HEXADECIMAL #***/
/**
 * print_hexadecimal - Prints unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Integer values printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***# PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL #***/
/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of char of type int
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***# PRINT HEXX NUM IN LOWER OR UPPER #***/
/**
 * print_hexa - Output hexadecimal number in lower OR upper
 * @types: List arguments
 * @map_to: Values to map the number to
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @flag_ch: Calculates active flags (same as above)
 * @width: Width
 * @precision: Precision
 * @size: Size
 * @size: Size
 * Return: Hexa decimal number
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);
	unsigned long int num2 = num1;

	UNUSED(width);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[b--] = map_to[num1 % 16];
		num1 /= 16;
	}

	if (flags & F_HASH && num2 != 0)
	{
		buffer[b--] = flag_ch;
		buffer[b--] = '0';
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}
