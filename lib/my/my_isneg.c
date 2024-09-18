/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** function my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    char zero = '0';

    if (n >= 0) {
        putchar('P');
    } else {
        putchar('N');
    }
}
