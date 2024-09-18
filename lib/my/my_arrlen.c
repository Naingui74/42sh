/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_arrlen.c
*/

#include <stdlib.h>

int my_arrlen(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return 0;
    for (; tab[i] != NULL; i++);
    return i;
}
