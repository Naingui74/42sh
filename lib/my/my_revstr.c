/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** function my_compute_square_root
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char tmp = '0';

    for (i = 0; j > i; i++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j -= 1;
    }
    return str;
}
