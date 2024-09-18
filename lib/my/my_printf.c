/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Pool part 2
** function my_printf
*/

#include <stdarg.h>
#include "my.h"
#include "../../include/printf_func_ptr.h"
#include <stdio.h>

static int (*functions[])(va_list) = {
    &d_flag, &i_flag, &c_flag, &s_flag, &percent_flag,
    &hex_flag, &hex_flag_capital, &o_flag, &p_flag, &u_flag
};
static int (*precision_nb[])(va_list, int) = {
    &f_flag
};

static char flags[] = "dics%xXopu";
static char precision_flags[] = "f";

int check_precision(const char *format, int *i)
{
    int precision = 6;

    if (format[*i] == '.') {
        precision = my_getnbr(&format[*i + 1]);
        if (precision > 9)
            i += 1;
        *i += 2;
    }
    return precision;
}

int check_param(char c, va_list args, int precision)
{
    for (int i = 0; i < my_strlen(flags); i += 1) {
        if (flags[i] == c) {
            functions[i](args);
            return 0;
        }
    }
    for (int j = 0; j < my_strlen(precision_flags); j += 1) {
        if (precision_flags[j] == c) {
            precision_nb[j](args, precision);
            return 0;
        }
    }
    return 84;
}

int my_printf(const char *format, ...)
{
    int err = 0;
    int precision;
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i += 1) {
        if (format[i] == '%') {
            i += 1;
            precision = check_precision(format, &i);
            err = check_param(format[i], args, precision);
        } else
            my_putchar(format[i]);
        if (format[i - 1] == '%' && err == 84) {
            my_putchar(format[i - 1]);
            my_putchar(format[i]);
        }
    }
    if (err == 84)
        return 84;
    return 0;
}
