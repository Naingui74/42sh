/*
** EPITECH PROJECT, 2023
** my_puthex
** File description:
** function to convert print
** the adress of a function
*/

#include "../my.h"

int my_putptr(unsigned long nb)
{
    char hex[my_nbrlen(nb)];
    int i = 0;
    int temp;

    my_putstr("0x");
    for (i = 0; nb != 0; i += 1) {
        temp = 0;
        temp = nb % 16;
        if (temp < 10)
            hex[i] = temp + 48;
        else
            hex[i] = temp + 87;
        nb = nb / 16;
    }
    my_revstr(hex);
    my_putstr(hex);
    return 0;
}
