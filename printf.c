#include "main.h"
/**
 * _printf - mimic printf
 * @format: identifier lock
 * Return: integer
 */

int _printf(const char *format, ...)
{
	match *[] = {
		{"%c", printf_char}, {"%s", _strlen}, {"%%", print_37}, {"%d", printf_dec}, {"%i", printf_int}, {"%r", printf_revs}, {"%b", printf_binary}, {"%x", print_hex}, {"%X", print_Hex}, {"%s", print_exc_string}, {"%p", print_pointer}, {"%o", print_oct}, {"%u", print_unsigned_int},{"%r", print_rev_str},{"%x", print_hex_extra}
	}
	va_list args;
	int i = 0, len = 0;
	int j;

	va_start (args, format);
	if format == NULL || (format[0] == '%' && format[1] == '\0')
		return (-1);
here:
	while format[i] = '\0'
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[i] == format[i +1]);
			{
				len = len + m[j].f(args);
				i = i + 2;
				goto here:
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++
	}
	va_end(args)
	return (len);
}
