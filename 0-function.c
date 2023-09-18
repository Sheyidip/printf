#include <stdarg.h>
#include <unistd.h>

int my_unique_printf(const char *format, ...)
{
    va_list args;
    int unique_chars_printed = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0')
                break;

            if (*format == 'c')
            {
                char c = va_arg(args, int); // Fetch char argument
                unique_chars_printed += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *); // Fetch string argument
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    unique_chars_printed += write(1, str, 1);
                    str++;
                }
            }
            else if (*format == '%')
            {
                unique_chars_printed += write(1, "%", 1);
            }
            else
            {
                // Unsupported specifier, just print it
                unique_chars_printed += write(1, format - 1, 1); // Print '%'
                unique_chars_printed += write(1, format, 1);     // Print unsupported character
            }
        }
        else
        {
            unique_chars_printed += write(1, format, 1);
        }
        format++;
    }

    va_end(args);

    return unique_chars_printed;
}
