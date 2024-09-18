/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_env.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

char **copy_env(all_t *all, char **env)
{
    int i = 0;

    if (!env)
        return NULL;
    all->shell.my_env = malloc(sizeof(char *) * (my_arrlen(env) + 1));
    for (; env[i] != NULL; i++) {
        all->shell.my_env[i] = my_strdup(env[i]);
    }
    all->shell.my_env[i] = NULL;
    return all->shell.my_env;
}

int my_env(all_t *all)
{
    printf_list(all);
    return 0;
}
