#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024


#define F_MINUS 1

#define UNUSED(x) (void)(x)
typedef struct format
{
	char*id;
	int (*f)();
} match;

int _putchar(char c);
int printf_char(va_list val);
int _strlen(char *str);
int _printf(const char *format, ...);
int print_37(void);
int print_percent(void);
int _strlenc(const char *str);
int printf_binary(va_list val);
int printf_int(va_list args);
int printf_dec(va_list args);
int print_unsigned_int(va_list args);
int print_oct(va_list val);
int print_hex(va_list val);
int print_Hex(va_list val);
int print_exc_string(va_list val);
int print_pointer(va_list val);
int print_hex_extra(unsigned long int num);
int print_rev_str(va_list val);
int print_unsigned_int(va_list args);
#endif /* MAIN_H */
