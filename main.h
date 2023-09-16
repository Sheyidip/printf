#ifndef MY_PRINTF_MAIN_H
#define MY_PRINTF_MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_MY(x) (void)(x)
#define BUFF_SIZE_MY 1024

/* FLAGS */
#define F_MINUS_MY (1 << 0)
#define F_PLUS_MY (1 << 1)
#define F_ZERO_MY (1 << 2)
#define F_HASH_MY (1 << 3)
#define F_SPACE_MY (1 << 4)

/* SIZES */
#define S_LONG_MY (1 << 0)
#define S_SHORT_MY (1 << 1)

/**
 * struct fmt_my - Struct op
 *
 * @fmt_my: The format.
 * @fn_my: The function associated.
 */
struct fmt_my
{
    char fmt_my;
    int (*fn_my)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt_my fmt_t_my - Struct op
 *
 * @fmt_my: The format.
 * @fn_t_my: The function associated.
 */
typedef struct fmt_my fmt_t_my;

int _printf_my(const char *format_my, ...);
int handle_print_my(const char *fmt_my, int *i_my,
                    va_list list_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_string_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_percent_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/* Functions to print numbers */
int print_int_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_binary_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_unsigned_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_octal_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_hexadecimal_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int print_hexa_upper_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

int print_hexa_my(va_list types_my, char map_to_my[], char buffer_my[], int flags_my, char flag_ch_my, int width_my, int precision_my, int size_my);

/* Function to print non-printable characters */
int print_non_printable_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/* Function to print memory address */
int print_pointer_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/* Functions to handle other specifiers */
int get_flags_my(const char *format_my, int *i_my);
int get_width_my(const char *format_my, int *i_my, va_list list_my);
int get_precision_my(const char *format_my, int *i_my, va_list list_my);
int get_size_my(const char *format_my, int *i_my);

/* Function to print a string in reverse */
int print_reverse_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/* Function to print a string in rot13 */
int print_rot13string_my(va_list types_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/* Width handler */
int handle_write_char_my(char c_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int write_number_my(int is_positive_my, int ind_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);
int write_num_my(int ind_my, char bff_my[], int flags_my, int width_my, int precision_my, int length_my, char padd_my, char extra_c_my);
int write_pointer_my(char buffer_my[], int ind_my, int length_my, int width_my, int flags_my, char padd_my, char extra_c_my, int padd_start_my);

int write_unsgnd_my(int is_negative_my, int ind_my, char buffer_my[], int flags_my, int width_my, int precision_my, int size_my);

/****************** UTILS ******************/
int is_printable_my(char);
int append_hexa_code_my(char, char[], int);
int is_digit_my(char);

long int convert_size_number_my(long int num_my, int size_my);
long int convert_size_unsgnd_my(unsigned long int num_my, int size_my);

#endif /* MY_PRINTF_MAIN_H */
