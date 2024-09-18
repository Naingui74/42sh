/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** function my_putnbr
*/

#include "my.h"

int my_putnbr(long nb)
{
    int temp_nb = nb;

    if (nb != temp_nb) {
        my_stderr("\n[my_putnbr] ERROR: Overflow\n");
        return 84;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
