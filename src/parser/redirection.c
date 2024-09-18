/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** redirection.c
*/

#include "../../include/minishell.h"

void redirect_superior(all_t *all, int *stdout_copy)
{
    int file = 0;

    if (all->redirect.superior_type == 1) {
        *stdout_copy = dup(STDOUT_FILENO);
        file = open(all->redirect.redirect_sup, O_WRONLY | O_CREAT |
        O_TRUNC, 0666);
        if (file == -1)
            exit(all->shell.my_status);
        if (dup2(file, STDOUT_FILENO) == -1)
            exit(EXIT_FAILURE);
        close(file);
    }
}

void redirect_superior2(all_t *all, int *stdout_copy)
{
    int file = 0;

    if (all->redirect.superior_type == 2) {
        *stdout_copy = dup(STDOUT_FILENO);
        file = open(all->redirect.redirect_supsup, O_WRONLY | O_CREAT |
        O_APPEND, 0666);
        if (file == -1)
            exit(all->shell.my_status);
        if (dup2(file, STDOUT_FILENO) == -1)
            exit(EXIT_FAILURE);
        close(file);
    }
}

void redirect_inferior(all_t *all, int *stdin_copy)
{
    int file = 0;

    if (all->redirect.inferior_type == 1) {
        *stdin_copy = dup(STDIN_FILENO);
        file = open(all->redirect.redirect_left, O_RDONLY, 0666);
        if (file == -1)
            exit(all->shell.my_status);
        if (dup2(file, STDIN_FILENO) == -1)
            exit(EXIT_FAILURE);
        close(file);
    }
}

void redirect_inferior2(all_t *all, int *stdin_copy)
{
    int file = 0;

    if (all->redirect.inferior_type == 2) {
        *stdin_copy = dup(STDIN_FILENO);
        file = open(all->redirect.redirect_leftleft, O_RDONLY | O_CREAT |
        O_APPEND, 0666);
        if (file == -1)
            exit(all->shell.my_status);
        if (dup2(file, STDIN_FILENO) == -1)
            exit(EXIT_FAILURE);
        close(file);
        printf("%s\n", all->redirect.redirect_leftleft);
    }
}

void restore_stdout_stdin(all_t *all, int stdout_copy, int stdin_copy)
{
    if (stdout_copy != -1) {
        if (dup2(stdout_copy, STDOUT_FILENO) == -1)
            exit(all->shell.my_status);
        close(stdout_copy);
    }
    if (stdin_copy != -1) {
        if (dup2(stdin_copy, STDIN_FILENO) == -1)
            exit(all->shell.my_status);
        close(stdout_copy);
    }
}
