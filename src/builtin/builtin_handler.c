/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** builtin_handler.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

int is_builtin(all_t *all)
{
    const char *builtins[] = {"cd", "exit", "env", "setenv", "unsetenv",
    "history", "!", "which", "where", "repeat", NULL};

    for (int i = 0; builtins[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[0], builtins[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

static
void setenv_condition(all_t *all)
{
    if (all->shell.cmd[1] != NULL)
        my_setenv(all, all->shell.cmd[1]);
    if (all->shell.cmd[1] == NULL)
        my_env(all);
}

void pars_history(all_t *all)
{
    if (my_strcmp(all->shell.cmd[0], "history") == 0 &&
    all->shell.history == 1 && all->shell.cmd[1] == NULL)
        print_history();
    if (my_strcmp(all->shell.cmd[0], "history") == 0 &&
    all->shell.history == 1 && all->shell.cmd[1] != NULL &&
    my_strcmp(all->shell.cmd[1], "-c") == 0)
        clear_history();
    if (my_strcmp(all->shell.cmd[0], "history") == 0 &&
    all->shell.history == 1 && all->shell.cmd[1] != NULL &&
    my_strcmp(all->shell.cmd[1], "-r") == 0)
        print_reverse(all);
}

static
void which(char *program)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char *malloc_path = NULL;

    while (dir != NULL) {
        malloc_path = malloc(strlen(dir) + strlen(program) + 2);
        sprintf(malloc_path, "%s/%s", dir, program);
        if (access(malloc_path, X_OK) == 0) {
            printf("%s\n", malloc_path);
            return;
        }
        dir = strtok(NULL, ":");
    }
}

static
void where(char *program)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char *malloc_path = NULL;

    while (dir != NULL) {
        malloc_path = malloc(strlen(dir) + strlen(program) + 2);
        sprintf(malloc_path, "%s/%s", dir, program);
        if (access(malloc_path, X_OK) == 0)
            printf("%s\n", malloc_path);
        dir = strtok(NULL, ":");
    }
}

int func_to_call(all_t *all)
{
    if (my_strcmp(all->shell.cmd[0], "which") == 0) {
        if (all->shell.cmd[1] != NULL)
            which(all->shell.cmd[1]);
        else {
            all->shell.my_status = 1;
            return all->shell.my_status;
            printf("which: Too few arguments.\n");
        }
    }
    if (my_strcmp(all->shell.cmd[0], "where") == 0) {
        if (all->shell.cmd[1] != NULL)
            where(all->shell.cmd[1]);
        else {
            printf("where: Too few arguments.\n");
            all->shell.my_status = 1;
            return all->shell.my_status;
        }
    }
    return 0;
}

void execute_builtin(all_t *all)
{
    char *new_value = concatenate_name_value("OLDPWD", getcwd(NULL, 0));

    if (my_strcmp("exit", all->shell.cmd[0]) == 0) {
        my_putstr("exit\n");
        exit(all->shell.my_status);
    }
    if (my_strcmp(all->shell.cmd[0], "env") == 0)
        my_env(all);
    if (my_strcmp(all->shell.cmd[0], "cd") == 0) {
        my_cd(all);
        modify_node_value(all, "OLDPWD", new_value);
    }
    if (my_strcmp(all->shell.cmd[0], "unsetenv") == 0)
        my_unsetenv(all);
    if (my_strcmp(all->shell.cmd[0], "setenv") == 0)
        setenv_condition(all);
    func_to_call(all);
    pars_history(all);
}
