
#include "main.h"
#include <stdarg.h>



/************************* CUSTOM PRINT BINARY *************************/

/**
 * custom_print_binary - Custom function to print an unsigned number in binary
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Flag settings
 * @width: Width setting
 * @precision: Precision setting
 * @size: Size specification
 *
 * Return: Number of characters printed
 */
int custom_print_binary(va_list args, char buffer[],
        int flags, int width, int precision, int size)
{
        unsigned int number = va_arg(args, unsigned int);
        int printed_chars = 0;
        int binary_digits[32];
        int num_of_digits = 0;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        
        for (int i = 0; i < 32; i++) {
            binary_digits[i] = (number >> (31 - i)) & 1;
        }

        
        int start_printing = 0;
        for (int i = 0; i < 32; i++) {
            if (binary_digits[i] == 1) {
                start_printing = i;
                break;
            }
        }

        
        for (int i = start_printing; i < 32; i++) {
            char binary_char = '0' + binary_digits[i];
            printed_chars += write(1, &binary_char, 1);
            num_of_digits++;
        }

        if (num_of_digits == 0) {
            printed_chars += write(1, "0", 1);
        }

        return (printed_chars);
}

/************************* CUSTOM PRINT INTEGER *************************/

/**
 * custom_print_int - Custom function to print an integer
 * @args: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Flag settings
 * @width: Width setting
 * @precision: Precision setting
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int custom_print_int(va_list args, char buffer[],
        int flags, int width, int size)
{
        long int number = va_arg(args, long int);
        int printed_chars = 0;
        int is_negative = 0;
        char temp_buffer[BUFF_SIZE];
        int index = 0;

        number = custom_convert_size_number(number, size);

        if (number < 0)
        {
            is_negative = 1;
            number = -number;
        }

        if (number == 0)
        {
            temp_buffer[index++] = '0';
        }
        else
        {
            while (number != 0)
            {
                temp_buffer[index++] = '0' + (number % 10);
                number /= 10;
            }
        }

        if (is_negative)
        {
            temp_buffer[index++] = '-';
        }

        int padding = width - index;
        if (flags & F_MINUS)
        {
          
            for (int i = 0; i < index; i++)
            {
                buffer[printed_chars++] = temp_buffer[i];
            }
            for (int i = 0; i < padding; i++)
            {
                buffer[printed_chars++] = ' ';
            }
        }
        else
        {
            
            for (int i = 0; i < padding; i++)
            {
                buffer[printed_chars++] = ' ';
            }
            for (int i = 0; i < index; i++)
            {
                buffer[printed_chars++] = temp_buffer[i];
            }
        }

        return (printed_chars);
}
