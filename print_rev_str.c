#include "main.h"
/**
 * print_rev_str - prints string in reverse
 * @val: value to be printed
 * Return: the string
 */
int print_rev_str(va_list val)
{
	char *s = va_arg(val, char *);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j = 1; i >= 0; i++)
		_putchar(s[i]);
	return (j);
}
