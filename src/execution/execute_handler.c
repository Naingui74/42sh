/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** parsing.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

static
int check_acces(all_t *all)
{
    char *path = all->shell.cmd[0];

    if (access(path, F_OK) != 0 && my_strcmp(path, "set") != 0) {
        my_stderr(path);
        my_stderr(": Command not found.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    if (access(path, X_OK) != 0 && my_strcmp(path, "set") != 0) {
        my_stderr(path);
        my_stderr(": Permission denied.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    return 0;
}

int execute_binary(all_t *all)
{
    char *path = all->shell.cmd[0];

    if (path != NULL && access(path, X_OK) == 0) {
        if (execve(path, all->shell.cmd, NULL) == -1 && errno != ENOEXEC) {
            my_stderr(path);
            my_stderr(": Permission denied.\n");
            all->shell.my_status = 1;
            return all->shell.my_status;
        }
    }
    if (errno == ENOEXEC) {
        my_stderr(path);
        my_stderr(": Exec format error. Wrong Architecture.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    check_acces(all);
    return 0;
}

static void display_variable(all_t *all)
{
    variables_t *curr = all->shell.variables;
    char *str = malloc(sizeof(char) + my_strlen(all->shell.cmd[1]));
    int index = 0;
    int found = 0;

    for (size_t i = 1; i < strlen(all->shell.cmd[1]); i += 1) {
        str[index] = all->shell.cmd[1][i];
        index += 1;
    }
    str[index] = '\0';
    while (curr != NULL) {
        if (my_strcmp(str, curr->variable) == 0) {
            my_printf("%s\n", curr->value);
            found = 1;
        }
        curr = curr->next;
    }
    if (!found)
        fprintf(stderr, "%s: Undefined variable.\n", str);
}

int call_exec(all_t *all)
{
    char *path = NULL;

    path = path_loop(all, all->shell.cmd[0]);
    if (my_strcmp(all->shell.cmd[0], "echo") == 0) {
        if (all->shell.cmd[1] != NULL && all->shell.cmd[1][0] == '$') {
            display_variable(all);
            return OK;
        }
    }
    if (path != NULL && access(path, X_OK) == 0) {
        if (execve(path, all->shell.cmd, all->shell.my_env) == -1)
            all->shell.my_status = 1;
    } else
        return execute_binary(all);
    return 0;
}

int execute_command(all_t *all)
{
    pid_t pid = fork();
    int status = 0;

    if (pid < 0) {
        return 84;
    }
    if (pid == 0) {
        call_exec(all);
        exit(all->shell.my_status);
    } else {
        waitpid(pid, &status, 0);
        status = handle_child_exit_status(all, status);
        all->shell.my_status = status;
        return status;
    }
}

static
int check_coredump(all_t *all, int status)
{
    if (WCOREDUMP(status)) {
        my_stderr(" (core dumped)\n");
        return all->shell.my_status;
    }
    return 0;
}

int handle_child_exit_status(all_t *all, int status)
{
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV) {
            my_stderr("Segmentation fault");
            check_coredump(all, status);
            return 128 + WTERMSIG(status);
        }
        if (WTERMSIG(status) == SIGFPE) {
            my_stderr("Floating exception");
            check_coredump(all, status);
            return 128 + WTERMSIG(status);
        }
        return 128 + WTERMSIG(status);
    } else {
        return 84;
    }
}
