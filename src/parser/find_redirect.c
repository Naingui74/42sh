/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** find_redirect.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

int superior_redirect(all_t *all)
{
    for (int i = 0; all->shell.cmd[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[i], ">") == 0) {
            all->redirect.redirect_sup = all->shell.cmd[i + 1];
            all->shell.cmd[i] = NULL;
            return 1;
        }
    }
    for (int i = 0; all->shell.cmd[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[i], ">>") == 0) {
            all->redirect.redirect_supsup = all->shell.cmd[i + 1];
            all->shell.cmd[i] = NULL;
            return 2;
        }
    }
    return 0;
}

int inferior_redirect(all_t *all)
{
    for (int i = 0; all->shell.cmd[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[i], "<") == 0) {
            all->redirect.redirect_left = all->shell.cmd[i + 1];
            all->shell.cmd[i] = NULL;
            return 1;
        }
    }
    for (int i = 0; all->shell.cmd[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[i], "<<") == 0) {
            all->redirect.redirect_leftleft = all->shell.cmd[i + 1];
            all->shell.cmd[i] = NULL;
            return 2;
        }
    }
    return 0;
}
