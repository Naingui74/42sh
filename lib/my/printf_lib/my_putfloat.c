/*
** EPITECH PROJECT, 2023
** my_putfloat
** File description:
** function to print a
** float number
*/

#include "../my.h"

#include <stdio.h>

int my_putfloat(double nb, int precision)
{
    long nb_integer = nb;
    double nb_double = nb - nb_integer;
    long result;

    if (precision != 0) {
        my_putnbr(nb_integer);
        my_putchar('.');
        result = nb_double * my_compute_power_rec(10, precision + 2);
        if ((result % 100) > 50) {
            result += 100;
        }
        result /= 100;
        my_putnbr(result);
    } else
        my_putnbr(nb_integer);
    return 0;
}
