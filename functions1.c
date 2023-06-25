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

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
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
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int N = num;

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
 * Return: Number of characters of type int
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/***# PRINT A HEXX DECIMAL NUM IN LOWER OR UPPER #***/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @flag_ch: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * @size: Size (specifier)
 * Return: Hexadecimal number
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int N = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[x--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && N != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
