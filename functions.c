#include "main.h"
#include <stdarg.h>

/**
 * _printf_char - function to print a character
 * @val: Arguments
 * Return: 1
 */
int _printf_char(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);
}

/**
 * _strlen - function to returns the length of a string
 * @str: string pointer
 * Return: i
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	return (i);
}
/**
 * _strlenc -  function for constant character
 * @str: character pointer
 * Return: i
 */
int _strlenc(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	return (i);
}
/**
 * _printf_percent - prints % sign
 * Return: integer
 */
int _print_percent(void)
{
	_putchar(37);
	return (1);
}
