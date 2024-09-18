/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** loop.c
*/

#include "lexer.h"
#include "minishell.h"

int loop_pipe(all_t *all, or_t *or_tab)
{
    if (or_tab == NULL)
        return 84;
    if (or_tab->size_pipe == 0) {
        remove_first_space(or_tab->pipe[0]->cmd);
        command_in_loop(all, or_tab->pipe[0]->cmd);
    } else
        for (int i = 0; i != or_tab->size_pipe + 1; i++) {
            remove_first_space(or_tab->pipe[i]->cmd);
            command_in_loop(all, or_tab->pipe[i]->cmd);
        }
    return 0;
}

int loop_or(all_t *all, and_t *and_tab)
{
    bool is_wrong_cmd = true;

    if (and_tab == NULL)
        return 84;
    if (and_tab->size_or == 0)
        loop_pipe(all, and_tab->or_tab[0]);
    else
        for (int i = 0; i != and_tab->size_or + 1 && is_wrong_cmd; i++) {
            loop_pipe(all, and_tab->or_tab[i]);
            is_wrong_cmd = all->shell.my_status != 0 ? true : false;
        }
    return 0;
}

int loop_and(all_t *all, semicolons_t *sm_tab)
{
    bool is_good_cmd = true;

    if (sm_tab == NULL)
        return 84;
    if (sm_tab->size_and == 0)
        loop_or(all, sm_tab->and_tab[0]);
    else
        for (int j = 0; j != sm_tab->size_and + 1 && is_good_cmd; j++) {
            loop_or(all, sm_tab->and_tab[j]);
            is_good_cmd = all->shell.my_status == 0 ? true : false;
    }
    return 0;
}

int loop_semicolons(all_t *all)
{
    if (all->lexer->size_sm == 0)
        loop_and(all, all->lexer->sm[0]);
    else
        for (int i = 0; i != all->lexer->size_sm + 1; i++)
            loop_and(all, all->lexer->sm[i]);
    return 0;
}
