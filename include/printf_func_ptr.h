/*
** EPITECH PROJECT, 2023
** printf.h
** File description:
** printf.h header
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>
    #include <stdarg.h>

int d_flag(va_list args);
int i_flag(va_list args);
int c_flag(va_list args);
int s_flag(va_list args);
int percent_flag(va_list args);
int hex_flag(va_list args);
int hex_flag_capital(va_list args);
int o_flag(va_list args);
int p_flag(va_list args);
int u_flag(va_list args);
int f_flag(va_list args, int precision);

#endif
