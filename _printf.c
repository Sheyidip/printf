#include "main.h"

void my_print_buffer(char my_buffer[], int *my_buff_ind);

/**
 * my_unique_printf - My unique printf function
 * @my_format: The format string
 * Return: The number of characters printed
 */
int my_unique_printf(const char *my_format, ...)
{
    int i, my_printed_chars = 0;
    int my_flags, my_width, my_precision, my_size, my_buff_ind = 0;
    va_list my_list;
    char my_buffer[BUFF_SIZE_MY];

    if (my_format == NULL)
        return (-1);

    va_start(my_list, my_format);

    for (i = 0; my_format && my_format[i] != '\0'; i++)
    {
        if (my_format[i] != '%')
        {
            my_buffer[my_buff_ind++] = my_format[i];
            if (my_buff_ind == BUFF_SIZE_MY)
                my_print_buffer(my_buffer, &my_buff_ind);
            my_printed_chars++;
        }
        else
        {
            my_print_buffer(my_buffer, &my_buff_ind);
            my_flags = get_flags_my(my_format, &i);
            my_width = get_width_my(my_format, &i, my_list);
            my_precision = get_precision_my(my_format, &i, my_list);
            my_size = get_size_my(my_format, &i);
            ++i;
            my_printed = handle_print_my(my_format, &i, my_list, my_buffer,
                my_flags, my_width, my_precision, my_size);
            if (my_printed == -1)
                return (-1);
            my_printed_chars += my_printed;
        }
    }

    my_print_buffer(my_buffer, &my_buff_ind);

    va_end(my_list);

    return (my_printed_chars);
}

/**
 * my_print_buffer - Prints the contents of my buffer
 * @my_buffer: The character buffer
 * @my_buff_ind: The buffer index
 */
void my_print_buffer(char my_buffer[], int *my_buff_ind)
{
    if (*my_buff_ind > 0)
        write(1, &my_buffer[0], *my_buff_ind);

    *my_buff_ind = 0;
}
