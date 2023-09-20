#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * get_flags_my - Tells the function how to interprete the argument
 * @format_my: Argument specifier
 * @int_my: integer specifier
 * Return: argument given based on format specifier
 */
int get_flags_my(const char *format_my, int int_my)
{
	const char *ptr = format_my;

	va_list types_my;

	va_start(types_my, format_my);

	while (*ptr)
	{
		if (*ptr == '%')
		{
		ptr++;
		}
		switch (*ptr)
		{
			case'u':
			unsigned int unsigned var = va_arg(types_my, int_my);
			_printf("%u" unsigned int);
			break;

			case 'o':
			unsigned int octal = va_arg(types_my, int_my);
			_printf("%o" octal);
			break;

			case 'x':
			unsigned int hexadecimal = va_arg(types_my, int_my);
			_printf("%x" hexadecimal);
			break;

			case 'X':
			unsigned int upper hexadecimal = va_arg(types_my, int_my);
			_printf("%X" upper hexadecimal);
			break;
		
		default:
		putchar('%');
		putchar(*ptr);
		}
		putchar(*ptr);
		ptr++;
	}
	va_end(types_my);
}
