/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main.c
*/

#include "../include/minishell.h"

int main_handling(int argc, char **argv)
{
    if (argc != 1)
        return 84;
    if (argv[0] == NULL)
        return 84;
    return 0;
}

void init_struct(all_t *all, char **env)
{
    all->shell.my_env = copy_env(all, env);
    all->list = tab_to_linked_list(all);
    modify_node_value(all, "OLDPWD", "OLDPWD=");
    all->shell.my_env = linked_list_to_tab(all);
}

int main(int argc, char **argv, char **envp)
{
    all_t *all = malloc(sizeof(all_t));
    int result = 0;

    if (main_handling(argc, argv) == KO)
        return KO;
    init_struct(all, envp);
    result = minishell1(all);
    free_all(all);
    return result;
}
