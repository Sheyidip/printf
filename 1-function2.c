# include "main.h"
#include <stdarg.h>


/************* CUSTOM PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *************/

/**
 * custom_print_hexa_upper - Custom function to print an unsigned number
 *                           in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 *
 * Return: Number of characters printed
 */
int custom_print_hexa_upper(va_list args, char buffer[])
{
    return (custom_print_hexa(args, "0123456789ABCDEF", buffer, 'X'));
}

/************** CUSTOM PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER **************/

/**
 * custom_print_hexa - Custom function to print a hexadecimal number in lower or upper case
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array for printing
 * @flag_ch: Character for '#' flag
 *
 * Return: Number of characters printed
 */
int custom_print_hexa(va_list args, char map_to[], char buffer[], char flag_ch)
{
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int original_number = number;
    int printed_chars = 0;

    
    if (original_number != 0)
    {
        buffer[printed_chars++] = flag_ch;
        buffer[printed_chars++] = '0';
    }

    
    char hex_str[BUFF_SIZE];
    int hex_str_index = 0;

    if (number == 0)
    {
        hex_str[hex_str_index++] = '0';
    }
    else
    {
        while (number > 0)
        {
            hex_str[hex_str_index++] = map_to[number % 16];
            number /= 16;
        }
    }

  
    for (int i = hex_str_index - 1; i >= 0; i--)
    {
        buffer[printed_chars++] = hex_str[i];
    }

    return (printed_chars);
}

