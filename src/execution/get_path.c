/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** get_path.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

char *my_getenv(all_t *all, char *name)
{
    int len = my_strlen(name);

    if (all == NULL || name == NULL)
        return NULL;
    all->shell.my_env = linked_list_to_tab(all);
    if (all->shell.my_env == NULL)
        return NULL;
    for (int i = 0; all->shell.my_env[i] != NULL; i++) {
        if (all->shell.my_env[i] != NULL &&
        my_strncmp(all->shell.my_env[i], name, len) == 0 &&
        all->shell.my_env[i][len] == '=')
            return all->shell.my_env[i] + len + 1;
    }
    return NULL;
}

int concat_path(all_t *all)
{
    all->shell.path = my_getenv(all, "PATH");
    if (all->shell.path == NULL)
        return 84;
    all->shell.concat_path = split(all->shell.path, ":");
    if (all->shell.concat_path == NULL)
        return 84;
    return 0;
}

int concat_home(all_t *all)
{
    all->shell.home = my_getenv(all, "HOME");
    if (all->shell.home == NULL) {
        return 84;
    }
    return 0;
}

char *path_loop(all_t *all, char *str)
{
    char *new_path = NULL;

    concat_path(all);
    for (int j = 0; all->shell.concat_path[j] != NULL; j++) {
        new_path = malloc(my_strlen(all->shell.concat_path[j]) +
        1 + my_strlen(all->shell.cmd[0]) + 1);
        if (new_path == NULL)
            return NULL;
        my_strcpy(new_path, all->shell.concat_path[j]);
        my_strcat(new_path, "/");
        my_strcat(new_path, str);
        free(all->shell.concat_path[j]);
        all->shell.concat_path[j] = new_path;
        if (access(all->shell.concat_path[j], X_OK) == 0)
            return all->shell.concat_path[j];
    }
    free(new_path);
    return NULL;
}
