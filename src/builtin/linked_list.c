/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** linked_list.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

void add_node(all_t *all, char *value)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return;
    node->next = NULL;
    node->data = my_strdup(value);
    node->prev = all->list.last;
    if (all->list.last != NULL)
        all->list.last->next = node;
    else
        all->list.first = node;
    all->list.last = node;
}

linked_list_t tab_to_linked_list(all_t *all)
{
    all->list.first = NULL;
    all->list.last = NULL;
    all->node.data = NULL;
    all->node.next = NULL;
    all->node.prev = NULL;
    for (int i = 0; all->shell.my_env[i] != NULL; i ++) {
        add_node(all, all->shell.my_env[i]);
    }
    return all->list;
}

int printf_list(all_t *all)
{
    node_t *current = all->list.first;

    while (current != NULL) {
        my_printf("%s\n", current->data);
        current = current->next;
    }
    return 0;
}

void modify_node_value(all_t *all, char *name, char *new_value)
{
    node_t *node = find_node_with_name(all, name);

    if (node != NULL) {
        free(node->data);
        node->data = my_strdup(new_value);
    }
    return;
}

char **linked_list_to_tab(all_t *all)
{
    int count = 0;
    node_t *current = all->list.first;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    all->shell.my_env = malloc(sizeof(char *) * (count + 1));
    if (all->shell.my_env == NULL) {
        return NULL;
    }
    current = all->list.first;
    for (int i = 0; i < count; i++) {
        all->shell.my_env[i] = current->data;
        current = current->next;
    }
    all->shell.my_env[count] = NULL;
    return all->shell.my_env;
}
