#include "main.h"
#include <stdarg.h>
#include <stdio.h>


/************************* CUSTOM PRINT UNSIGNED NUMBER *************************/

/**
 * custom_print_unsigned - Custom function to print an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array for printing
 *
 * Return: Number of characters printed
 */
int custom_print_unsigned(va_list args, char buffer[])
{
    unsigned long int number = va_arg(args, unsigned long int);
    int printed_chars = 0;

    
    char num_str[BUFF_SIZE];
    int num_str_len = snprintf(num_str, BUFF_SIZE, "%lu", number);

    
    for (int i = 0; i < num_str_len; i++)
    {
        buffer[printed_chars++] = num_str[i];
    }

    return printed_chars;
}

/********************* CUSTOM PRINT UNSIGNED NUMBER IN OCTAL *******************/

/**
 * custom_print_octal - Custom function to print an unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 *
 * Return: Number of characters printed
 */
int custom_print_octal(va_list args, char buffer[])
{
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int original_number = number;
    int printed_chars = 0;

    
    if (original_number != 0)
    {
        buffer[printed_chars++] = '0';
    }

    
    char octal_str[BUFF_SIZE];
    int octal_str_index = 0;

    if (number == 0)
    {
        octal_str[octal_str_index++] = '0';
    }
    else
    {
        while (number > 0)
        {
            octal_str[octal_str_index++] = '0' + (number % 8);
            number /= 8;
        }
    }

    
    for (int i = octal_str_index - 1; i >= 0; i--)
    {
        buffer[printed_chars++] = octal_str[i];
    }

    return (printed_chars);
}

/***************** CUSTOM PRINT UNSIGNED NUMBER IN HEXADECIMAL ****************/

/**
 * custom_print_hexadecimal - Custom function to print an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array for printing
 *
 * Return: Number of characters printed
 */
int custom_print_hexadecimal(va_list args, char buffer[])
{
    return (custom_print_hexa(args, "0123456789abcdef", buffer, 'x'));
}

