/*
** EPITECH PROJECT, 2023
** my_puthex_capital
** File description:
** function to convert
** decimal into octal
*/

#include "../my.h"

int my_putoctal(unsigned int nb)
{
    char hex[my_nbrlen(nb)];
    int i = 0;
    int temp;

    for (i = 0; nb != 0; i += 1) {
        temp = 0;
        temp = nb % 8;
        if (temp < 10)
            hex[i] = temp + '0';
        else
            hex[i] = temp + '0';
        nb = nb / 8;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(hex[j]);
    }
    return 0;
}
