/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** set_env.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"

char *concatenate_name_value(char *name, char *value)
{
    int length_name_value = my_strlen(name) + 2 + my_strlen(value);
    char *new_value = malloc(sizeof(char) * length_name_value);

    if (new_value == NULL) {
        return NULL;
    }
    for (int i = 0; i < length_name_value; i++) {
        new_value[i] = '\0';
    }
    new_value = my_strcat(new_value, name);
    new_value = my_strcat(new_value, "=");
    new_value = my_strcat(new_value, value);
    return new_value;
}

node_t *find_node_with_name(all_t *all, char *name)
{
    node_t *current = all->list.first;

    while (current != NULL) {
        if (my_strncmp(current->data, name, my_strlen(name)) == 0
        && current->data[my_strlen(name)] == '=') {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int my_setenv_error_handling(all_t *all)
{
    if (my_isalpha(all->shell.cmd[1][0]) == 84 &&
    all->shell.cmd[1][0] != '_') {
        my_stderr("setenv: Variable name must begin with a letter.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    for (int i = 0; all->shell.cmd[1][i] != '\0'; i++)
        if (my_isalphanum(all->shell.cmd[1][i]) == 84 &&
        all->shell.cmd[1][i] != '_') {
            my_stderr("setenv: Variable name must contain"
            " alphanumeric characters.\n");
            all->shell.my_status = 1;
            return all->shell.my_status;
        }
    if (all->shell.cmd[3] != NULL && all->shell.cmd[2] != NULL) {
        my_stderr("setenv: Too many arguments.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    return 0;
}

int my_setenv(all_t *all, char *name)
{
    char *value = all->shell.cmd[2];
    node_t *node = find_node_with_name(all, name);
    char *new_value = NULL;

    if (all->shell.cmd[2] != NULL)
        new_value = concatenate_name_value(name, value);
    if (my_setenv_error_handling(all) == 1)
        all->shell.my_status = 1;
    if (node != NULL && new_value != NULL)
        modify_node_value(all, name, concatenate_name_value(name, value));
    if (node != NULL && all->shell.cmd[2] == NULL)
        modify_node_value(all, name, concatenate_name_value(name, ""));
    if (node == NULL && new_value != NULL)
        add_node(all, concatenate_name_value(name, value));
    if (node == NULL && all->shell.cmd[2] == NULL)
        add_node(all, concatenate_name_value(name, ""));
    all->shell.my_env = linked_list_to_tab(all);
    return 0;
}
