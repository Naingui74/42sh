/*
** EPITECH PROJECT, 2023
** my_nbrlen
** File description:
** function to calculate the
** length of a number
*/

#include "my.h"
#include <stdio.h>

int my_nbrlen(int nb)
{
    int counter = 0;
    int i = 0;

    if (nb < 0) {
        counter += 1;
    }
    for (; nb != 0; i += 1) {
            nb = nb / 10;
            counter += 1;
    }
    return counter;
}
