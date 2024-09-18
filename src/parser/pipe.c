/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** pipe.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"
#include <stdio.h>

int find_pipe(all_t *all)
{
    for (int i = 0; all->shell.cmd[i] != NULL; i++) {
        if (my_strcmp(all->shell.cmd[i], "|") == 0) {
            all->redirect.pipe = my_strdup(all->shell.cmd[i + 1]);
            all->redirect.pipe_arr = split(all->redirect.pipe, "");
            all->shell.cmd[i] = NULL;
            return 1;
        }
    }
    return 0;
}

void find_path_pipe(all_t *all)
{
    char *pipe1 = path_loop(all, all->shell.cmd[0]);

    execve(pipe1, all->shell.cmd, all->shell.my_env);
}

void find_path_pipe2(all_t *all)
{
    char *pipe2 = path_loop(all, all->redirect.pipe_arr[0]);

    execve(pipe2, all->redirect.pipe_arr, all->shell.my_env);
}

static
void child1_process(all_t *all, int *pipefd)
{
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    find_path_pipe(all);
}

static
void child2_process(all_t *all, int *pipefd)
{
    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    find_path_pipe2(all);
}

int pipe_action(all_t *all)
{
    int pipefd[2];
    int status;
    pid_t pid;
    pid_t pid2;

    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
        child1_process(all, pipefd);
    }
    pid2 = fork();
    if (pid2 == 0)
        child2_process(all, pipefd);
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);
    return 0;
}
