/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_unsetenv.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

linked_list_t *delete_node(all_t *all, char *name)
{
    node_t *node = find_node_with_name(all, name);

    if (node != NULL) {
        if (node->prev != NULL)
            node->prev->next = node->next;
        else
            all->list.first = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
        else
            all->list.last = node->prev;
        free(node);
    }
    return &all->list;
}

int my_unsetenv(all_t *all)
{
    node_t *node = NULL;

    if (all->shell.cmd[1] == NULL) {
        my_stderr("unsetenv: Too few arguments.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    for (int i = 1; all->shell.cmd[i] != NULL; i++) {
        if (all->shell.cmd[i] != NULL)
            node = find_node_with_name(all, all->shell.cmd[i]);
        if (node != NULL)
            delete_node(all, all->shell.cmd[i]);
    }
    return 0;
}
