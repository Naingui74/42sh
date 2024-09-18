/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** variables.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

static void add_node_variable(all_t *all, char *variable, char *value)
{
    variables_t *new = malloc(sizeof(variables_t));
    variables_t *curr = all->shell.variables;

    if (value == NULL && new == NULL)
        return;
    new->variable = my_strdup(variable);
    new->value = my_strdup(value);
    new->next = NULL;
    if (all->shell.variables == NULL) {
        all->shell.variables = new;
    } else {
        curr = all->shell.variables;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new;
    }
    all->shell.variables->index += 1;
}

int variables(all_t *all)
{
    variables_t *current = all->shell.variables;
    char **command = NULL;

    if (all->shell.cmd[0] == NULL)
        return KO;
    if (my_strcmp(all->shell.cmd[0], "set") == 0) {
        if (all->shell.cmd[1] != NULL) {
            command = split(all->shell.buffer, "= \t");
            add_node_variable(all, command[1], command[2]);
            return OK;
        }
    }
    return OK;
}
