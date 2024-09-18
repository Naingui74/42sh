/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n < my_strlen(src)) {
            dest[i] = '\0';
        }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
        if (i == n) {
            break;
        }
    }
    dest[i] = '\0';
    return dest;
}
