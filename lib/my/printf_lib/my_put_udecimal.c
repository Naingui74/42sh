/*
** EPITECH PROJECT, 2023
** my_put_u
** File description:
** function to show
** unsigned int
*/

#include "../my.h"

int my_put_udecimal(unsigned int nb)
{
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
