/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** function my_str_isnum
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    int isnotnum = 0;

    if (!str) {
        return 84;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            isnotnum = 1;
        }
    }
    if (isnotnum >= 1) {
        return 84;
    } else {
        return 0;
    }
}
