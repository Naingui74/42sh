/*
** EPITECH PROJECT, 2023
** my_puthex
** File description:
** function to convert
** decimal into hexadecimal
*/

#include "../my.h"

int my_puthex(unsigned int nb)
{
    char hex[my_nbrlen(nb)];
    long i = 0;
    long temp;

    for (i = 0; nb != 0; i += 1) {
        temp = 0;
        temp = nb % 16;
        if (temp < 10)
            hex[i] = temp + 48;
        else
            hex[i] = temp + 87;
        nb = nb / 16;
    }
    for (long j = i - 1; j >= 0; j--) {
        my_putchar(hex[j]);
    }
    return 0;
}
