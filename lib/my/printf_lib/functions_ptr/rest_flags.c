/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Pool part 2
** my_printf flags
*/

#include <stdarg.h>
#include "../../my.h"

int hex_flag(va_list args)
{
    my_puthex(va_arg(args, unsigned int));
    return 0;
}

int hex_flag_capital(va_list args)
{
    my_puthex_capital(va_arg(args, unsigned int));
    return 0;
}

int o_flag(va_list args)
{
    my_putoctal(va_arg(args, unsigned int));
    return 0;
}

int p_flag(va_list args)
{
    my_putptr((unsigned long)va_arg(args, void *));
    return 0;
}

int u_flag(va_list args)
{
    my_put_udecimal(va_arg(args, unsigned int));
    return 0;
}
