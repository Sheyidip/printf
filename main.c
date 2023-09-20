#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = vprintf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    vprintf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    vprintf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    vprintf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    vprintf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    vprintf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    vprintf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    vprintf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    vprintf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = vprintf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    vprintf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    vprintf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
