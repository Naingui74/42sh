/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** prompt.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"
#include <strings.h>

char *remove_first_space(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    while (str[i] != '\0') {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return str;
}

char *my_strrchr(char *name, char sep)
{
    char *good_part = NULL;

    if (!name)
        return NULL;
    for (int i = my_strlen(name) - 1; i > 0; i--) {
        if (name[i] == sep) {
            good_part = &name[i + 1];
            break;
        }
    }
    return good_part;
}

static
int check_oldpwd_presence(all_t *all)
{
    if (!find_node_with_name(all, "OLDPWD"))
        add_node(all, "OLDPWD=");
    return 0;
}

static
void prompt(all_t *all)
{
    char *username = my_getenv(all, "USER");
    char *host = my_getenv(all, "HOSTNAME");
    char *pwd = getcwd(NULL, 0);
    char *last_part = my_strrchr(pwd, '/');
    char *BOLD = "\x1b[1m";

    if (username != NULL && host != NULL && last_part != NULL)
        my_printf("%s[%s@%s %s]$ ", BOLD, username, host, last_part);
    else
        my_printf("%s$> ", BOLD);
}

void check_path_not_null(all_t *all)
{
    if (my_getenv(all, "PATH") != NULL)
        execute_command(all);
}

static
void call_execution(all_t *all)
{
    if (is_builtin(all))
        execute_builtin(all);
    else
        check_path_not_null(all);
}

int command_in_loop(all_t *all, char *cmd)
{
    int stdout_copy = -1;
    int stdin_copy = -1;

    all->shell.cmd = split(cmd, " \t");
    if (all->shell.cmd == NULL || all->shell.cmd[0] == NULL)
        return KO;
    all->redirect.superior_type = superior_redirect(all);
    all->redirect.inferior_type = inferior_redirect(all);
    redirect_superior(all, &stdout_copy);
    redirect_superior2(all, &stdout_copy);
    redirect_inferior2(all, &stdin_copy);
    call_execution(all);
    restore_stdout_stdin(all, stdout_copy, stdin_copy);
    variables(all);
    return 0;
}

static
void check_history(all_t *all)
{
    if (isatty(0))
        write_in_history(all);
}

static
void check_isatty(all_t *all)
{
    if (isatty(0))
        prompt(all);
}

int minishell1(all_t *all)
{
    char *buffer = NULL;
    size_t buff_size = 0;

    while (1) {
        check_oldpwd_presence(all);
        all->shell.pwd = getcwd(buffer, buff_size);
        check_isatty(all);
        if (getline(&buffer, &buff_size, stdin) == -1)
            return all->shell.my_status;
        if (strcmp(buffer, "\n") == 0)
            continue;
        all->lexer = lexer_parser(buffer);
        all->shell.buffer = my_strdup(buffer);
        check_history(all);
        if (all->lexer == NULL) {
            all->shell.my_status = 1;
            continue;
        } else
            loop_semicolons(all);
    }
}
