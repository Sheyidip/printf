#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024


#define F_MINUS 1

#define UNUSED(x) (void)(x)

int print_char(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int _strlenc(const char *str);
int print_binary(va_list val);
int print_int(va_list args);
int print_dec(va_list args);


long int custom_convert_size_number(long int number, int size);
int custom_write_number(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);

int custom_print_unsigned(va_list args, char buffer[]);
int custom_print_octal(va_list args, char buffer[]);
int custom_print_hexadecimal(va_list args, char buffer[]);
int custom_print_hexa_upper(va_list args, char buffer[]);
int custom_print_hexa(va_list args, char map_to[], char buffer[], char flag_ch);

#endif /* MAIN_H */

