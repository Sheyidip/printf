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

        return custom_handle_write_char(character, buffer, flags, width, precision, size);
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
        char *str = va_arg(args, char *);
        int str_length = 0, printed_chars = 0;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(size);

        if (str == NULL)
            str = "(null)";

        while (str[str_length] != '\0')
            str_length++;

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

            printed_chars += write(1, str, str_length);
        }

        return (printed_chars);
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
}




