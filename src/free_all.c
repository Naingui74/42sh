/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** free_all.c
*/

#include "../include/minishell.h"

static
void free_struct_shell(all_t *all)
{
    free(all->shell.concat_path);
    free(all->shell.cmd);
    free(all->shell.home);
    free(all->shell.input);
    free(all->shell.my_env);
    free(all->shell.old_pwd);
    free(all->shell.pwd);
    free(all->shell.path);
    free(all->shell.variables);
    free(all->shell.buffer);
    free(all->shell.input2);
}

static
void free_linked_list(all_t *all)
{
    node_t *current = all->list.first;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

static
void free_history(all_t *all)
{
    free(all->history.buff);
    free(all->history.cmd);
}

static
void free_redirect(all_t *all)
{
    free(all->redirect.pipe);
    free(all->redirect.redirect_left);
    free(all->redirect.redirect_leftleft);
    free(all->redirect.redirect_sup);
    free(all->redirect.redirect_supsup);
}

void free_variables(all_t *all)
{
    variables_t *current = all->shell.variables;
    variables_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current->variable);
        free(current->value);
        free(current);
        current = next;
    }
}

void free_all(all_t *all)
{
    free_struct_shell(all);
    free_history(all);
    free_redirect(all);
    free_variables(all);
    free_linked_list(all);
    free(all);
}
