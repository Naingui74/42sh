/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-sokoban-aaron.groux
** File description:
** my_copitab.c
*/

#include <stddef.h>
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int len_tab(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != NULL; i++)
        len++;
    return len;
}

char **my_copitab(char **src)
{
    char **tab = NULL;
    int len = len_tab(src);

    tab = malloc(sizeof(char *) * (len + 1));
    tab[len] = NULL;
    for (int i = 0; src[i] != NULL; i++)
        tab[i] = my_strdup(src[i]);
    return tab;
}

int len_clean_str(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] != '\n')
            j++;
        i++;
    }
    return j;
}

static
int len_space_clean_str(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ')
            j++;
        i++;
    }
    return j;
}

char *clean_str(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * len_clean_str(str) + 1);

    while (str[i] != '\0') {
        if (str[i] != '\n') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}

char *clean_all_str(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * len_space_clean_str(str) + 1);

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}
