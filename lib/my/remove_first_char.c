/*
** EPITECH PROJECT, 2023
** removefirstchar
** File description:
** removefirstchar.c
*/

#include <stdlib.h>
#include "my.h"

char *remove_first_char(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (i = 0; str[i + 1] != '\0'; i++) {
        str2[i] = str[i + 1];
    }
    str2[i] = '\0';
    return str2;
}
