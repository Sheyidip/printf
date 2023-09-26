#include "main.h"
/**
 * print_exc_string - print exclusive string
 * @val: value to be printed
 * Return: number of characters printed
 */

int print_exc_string(va_list val)
{
	char *s;
	int i, len = 0;
	int value;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			value = s[i];
			if (value < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_Hex_extra(value);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
