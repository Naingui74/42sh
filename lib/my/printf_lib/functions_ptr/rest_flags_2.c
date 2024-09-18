/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Pool part 2
** my_printf flags
*/

#include <stdarg.h>
#include "../../my.h"

int f_flag(va_list args, int precision)
{
    my_putfloat(va_arg(args, double), precision);
    return 0;
}
