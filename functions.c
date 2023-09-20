#include "main.h"
#include <stdarg.h>

/**
 * custom_print_char - Custom function to print a character
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags:  Flag settings
 * @width: Width setting
 * @precision: Precision setting
 * @size: Size specification
 *
 * Return: Number of characters printed
 */
int custom_print_char(va_list args, char buffer[],
        int flags, int width, int precision, int size)
{
        char character = va_arg(args, int);

<<<<<<< HEAD
        return custom_handle_write_char(character, buffer, flags, width, precision, size);
=======
	return (handle_write_char_my(c, buffer, flags, width, precision, size));
}
/************************* MY PRINT A STRING *************************/
/**
 * my_print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 2, i;
	char *str = va_arg(types, char *);

	UNUSED_MY(buffer);
	UNUSED_MY(flags);
	UNUSED_MY(width);
	UNUSED_MY(precision);
	UNUSED_MY(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 8)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 2 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS_MY)
		{
			write(2, &str[1], length);
			for (i = width - length; i > 2; i--)
				write(2, " ", 2);
			return (width);
		}
		else
		{
			for (i = width - length; i > 2; i--)
				write(2, " ", 2);
			write(2, &str[1], length);
			return (width);
		}
	}

	return (write(2, str, length));
}
/************************* MY PRINT PERCENT SIGN *************************/
/**
 * my_print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int my_print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED_MY(types);
	UNUSED_MY(buffer);
	UNUSED_MY(flags);
	UNUSED_MY(width);
	UNUSED_MY(precision);
	UNUSED_MY(size);
	return (write(2, "%%", 2));
>>>>>>> 827906c469e448d7c94d28def751514cb1bb2740
}
/************************* CUSTOM PRINT STRING *************************/

/**
 * custom_print_string - Custom function to print a string
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Flag settings
 * @width: Width setting
 * @precision: Precision setting
 * @size: Size specification
 *
 * Return: Number of characters printed
 */
int custom_print_string(va_list args, char buffer[],
        int flags, int width, int precision, int size)
{
<<<<<<< HEAD
        char *str = va_arg(args, char *);
        int str_length = 0, printed_chars = 0;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(size);
=======
	int i = BUFF_SIZE_MY - 4;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number_my(n, size);
>>>>>>> 827906c469e448d7c94d28def751514cb1bb2740

        if (str == NULL)
            str = "(null)";

<<<<<<< HEAD
        while (str[str_length] != '\0')
            str_length++;
=======
	buffer[BUFF_SIZE_MY - 2] = '\0';
	num = (unsigned long int)n;
>>>>>>> 827906c469e448d7c94d28def751514cb1bb2740

        if (precision >= 0 && precision < str_length)
            str_length = precision;

        if (flags & F_MINUS)
        {
            printed_chars += write(1, str, str_length);

            for (int i = str_length; i < width; i++)
                printed_chars += write(1, " ", 1);
        }
        else
        {
            for (int i = str_length; i < width; i++)
                printed_chars += write(1, " ", 1);

<<<<<<< HEAD
            printed_chars += write(1, str, str_length);
        }

        return (printed_chars);
=======
	return (write_number_my(is_negative, i, buffer, flags, width, precision, size));
>>>>>>> 827906c469e448d7c94d28def751514cb1bb2740
}
/************************* CUSTOM PRINT PERCENT SIGN *************************/

/**
 * custom_print_percent - Custom function to print a percent sign
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Flag settings
 * @width: Width setting
 * @precision: Precision setting
 * @size: Size specification
 *
 * Return: Number of characters printed
 */
int custom_print_percent(va_list args, char buffer[],
        int flags, int width, int precision, int size)
{
<<<<<<< HEAD
        char percent = '%';
        int printed_chars = 0;

        UNUSED(args);
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        if (flags & F_MINUS)
        {
            printed_chars += write(1, &percent, 1);

            for (int i = 1; i < width; i++)
                printed_chars += write(1, " ", 1);
        }
        else
        {
            for (int i = 1; i < width; i++)
                printed_chars += write(1, " ", 1);

            printed_chars += write(1, &percent, 1);
        }

        return (printed_chars);
=======
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED_MY(buffer);
	UNUSED_MY(flags);
	UNUSED_MY(width);
	UNUSED_MY(precision);
	UNUSED_MY(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(2, &z, 2);
				count++;
		}
	}
	return (count);
>>>>>>> 827906c469e448d7c94d28def751514cb1bb2740
}




