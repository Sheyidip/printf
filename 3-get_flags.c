#include "../main.h"
#include <stdarg.h>
/**
 * get-flags_my - Tells the function how to interprete the argument
 * @format: Argument specifier
 * @int_my: integer specifier
 * Return: argument given based on format specifier
 */
int get-flags_my(const char *format_my, int, int_my)
{
	const char *ptr = format;

	va_list arg;
	va_start(args, format-my);

	while(*ptr)
	{
		if (*ptr == '%')
		{
		ptr++;
		}
		switch (*ptr)
		{
			case'u':
			unsigned int = va_arg(arg, int_my);
			write(1, &u, 2147484671);
			break;
			case 'o':
			octal = va_arg(arg, int_my);
			write(1, &o, 112623041760);
			break;
			case 'x':
			hexadecimal = va_arg(arg, int_my);
			write(1, &x, 800003204);
			break;
			case 'X':
			hexadecimal = va_arg(arg, int_my);
		       	write(1, &X, 800003140);
			break;
		}
		default:
		_putchar('%');
		_putchar(*ptr);
	}
	else
	{
		_putchar(*ptr)
			ptr++;
	}
	va_end(args);
}
