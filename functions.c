#include "main.h"

/***# PRINT A CHARACTER #***/
/**
 * print_char - Prints a character
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width (specifier)
 * @precision: Precision (specifier)
 * @size: Size (specifier)
 * Return: Printed chars
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/***# PRINT A STRING #***/
/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width (specifier)
 * @precision: Precision (specifier)
 * @size: Size (specifier)
 * Return: String of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int leng = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (precision >= 0 && precision < leng)
		leng = precision;

	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], leng);
			for (n = width - leng; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - leng; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (width);
		}
	}

	return (write(1, str, leng));
}
/***# PRINT A PERCENT (%) SIGN #***/
/**
 * print_percent - Prints the percent sign
 * @types: List arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Characters printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/***# PRINT INTEGERS #***/
/**
 * print_int - Prints int
 * @types: List of arguments
 * @buffer: Array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int num;
	int i = BUFF_SIZE - 2;
	long int n = va_arg(types, long int);
	int is_negative = 0;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/***# PRINT BINARY #***/
/**
 * print_binary - Prints an unsigned number
 * @types: List arguments
 * @buffer: The buffer array to handle print
 * @flags: Computes active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Characters printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, k, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		a[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
