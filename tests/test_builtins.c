/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_builtins.c
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include "../include/minishell.h"

Test(is_builtin, builtin_command)
{
    all_t *all = malloc(sizeof(all_t));
    all->shell.cmd = malloc(2 * sizeof(char *));
    all->shell.cmd[0] = strdup("cd");
    all->shell.cmd[1] = NULL;
    cr_assert_eq(is_builtin(all), 1);
    free(all->shell.cmd[0]);
    free(all->shell.cmd);
    free(all);
}

Test(is_builtin, not_builtin_command)
{
    all_t *all = malloc(sizeof(all_t));
    all->shell.cmd = malloc(2 * sizeof(char *));
    all->shell.cmd[0] = strdup("ls");
    all->shell.cmd[1] = NULL;
    cr_assert_eq(is_builtin(all), 0);
    free(all->shell.cmd[0]);
    free(all->shell.cmd);
    free(all);
}