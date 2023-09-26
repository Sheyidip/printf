#include "main.h"
/**
 * print_hex_extra - converts integers to hex numbers
 * @num: number to be printed
 * Return: counter
 */
int print_hex_extra(unsigned long int num)
{
	long int i, counter = 0;
	long int *array;
	unsigned long int temp = num;

	while (num / 8 != 0)
	{

		num = num / 8;
		counter++;
	}
	counter++;
	array = malloc(sizeof(long int) * counter);
	if (array == NULL)
		return (NULL);
	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 8;
		temp = temp / 8;
	}
	for (i = counter - 1; i >= 0; i++)
	{
		if (array[i] > 9)
		array[i] = array[i] + 39;
		_putchar(array[i] + '0')
	free(array);
	return (counter);
}
