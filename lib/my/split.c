/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** split.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../include/my.h"

int is_separator(char c, char *separators)
{
    for (int i = 0; separators[i]; i++) {
        if (c == separators[i]) {
            return 1;
        }
    }
    return 0;
}

static int count_word(char const *str, char *separators)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_separator(str[i], separators)) {
            in_word = 0;
            continue;
        }
        if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

int get_len(char *ptr, char *separators)
{
    int i = 0;

    for (; !is_separator(ptr[i], separators) && ptr[i] != '\0'; i++);
    return i;
}

char **split(char *str, char *separators)
{
    char **tab = NULL;
    char *tmp = NULL;
    int j = 0;

    tmp = (char *)str;
    tab = malloc(sizeof(char *) * (count_word(str, separators) + 1));
    while (*tmp != '\0') {
        tab[j] = malloc(sizeof(char) * (get_len(tmp, separators) + 1));
        my_strncpy(tab[j], tmp, get_len(tmp, separators));
        tab[j][get_len(tmp, separators)] = '\0';
        j += 1;
        tmp += get_len(tmp, separators);
        while (is_separator(*tmp, separators)) {
            tmp++;
        }
    }
    tab[j] = NULL;
    return (tab);
}
