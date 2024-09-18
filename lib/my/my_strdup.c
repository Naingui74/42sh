/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (dest == NULL)
        return NULL;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
