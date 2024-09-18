/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Pool part 2
** my_printf flags
*/

#include <stdarg.h>
#include "../../my.h"

int d_flag(va_list args)
{
    my_putnbr(va_arg(args, int));
    return 0;
}

int i_flag(va_list args)
{
    my_putnbr(va_arg(args, int));
    return 0;
}

int c_flag(va_list args)
{
    my_putchar(va_arg(args, int));
    return 0;
}

int s_flag(va_list args)
{
    my_putstr(va_arg(args, char *));
    return 0;
}

int percent_flag(void)
{
    my_putchar('%');
    return 0;
}
