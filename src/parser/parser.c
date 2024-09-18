/*
** EPITECH PROJECT, 2024
** Lexcer-Parser
** File description:
** parser.c
*/

#include "lexer.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
int init_struct(parser_t *parser)
{
    parser->size_sm = 0;
    parser->sm = malloc(sizeof(semicolons_t *));
    parser->sm[0] = malloc(sizeof(semicolons_t));
    parser->sm[0]->size_and = 0;
    parser->sm[0]->and_tab = malloc(sizeof(and_t *));
    parser->sm[0]->and_tab[0] = malloc(sizeof(and_t));
    parser->sm[0]->and_tab[0]->size_or = 0;
    parser->sm[0]->and_tab[0]->or_tab = malloc(sizeof(or_t *));
    parser->sm[0]->and_tab[0]->or_tab[0] = malloc(sizeof(or_t));
    parser->sm[0]->and_tab[0]->or_tab[0]->size_pipe = 0;
    parser->sm[0]->and_tab[0]->or_tab[0]->pipe = malloc(sizeof(pipe_t *));
    parser->sm[0]->and_tab[0]->or_tab[0]->pipe[0] = malloc(sizeof(pipe_t));
    return 0;
}

char *cat_string(char *tmp, char *cmd)
{
    char *new = NULL;
    int total = 0;

    if (tmp == NULL)
        total = my_strlen(cmd) + 1;
    else
        total = my_strlen(tmp) + my_strlen(cmd) + 2;
    new = malloc(sizeof(char) * total);
    if (new == NULL)
        return NULL;
    new[0] = '\0';
    if (tmp != NULL) {
        my_strcat(new, tmp);
        my_strcat(new, " ");
    }
    my_strcat(new, cmd);
    return new;
}

int choose_token(char *tmp, shell_t *shell)
{
    if (tmp == NULL || shell->parser_tree == NULL)
        return 84;
    if (shell->save_token == PIPES) {
        shell->parser_tree = check_pipe(shell->parser_tree, tmp);
    }
    if (shell->save_token == SEMICOLONS) {
        shell->parser_tree = check_semicolons(shell->parser_tree, tmp);
    }
    if (shell->save_token == AND) {
        shell->parser_tree = check_and(shell->parser_tree, tmp);
    }
    if (shell->save_token == OR) {
        shell->parser_tree = check_or(shell->parser_tree, tmp);
    }
    return 0;
}

int first_cmd(char *tmp, parser_t *tree)
{
    if (tmp == NULL || tree == NULL)
        return 84;
    tree->sm[0]->and_tab[0]->or_tab[0]->pipe[0]->cmd = strdup(tmp);
    return 0;
}

static
shell_t *add_value(char *tmp, shell_t *shell)
{
    if (shell->is_first == true && shell->head->token != IDENTIFIERS) {
        first_cmd(tmp, shell->parser_tree);
        shell->is_first = false;
    } else
        choose_token(tmp, shell);
    return shell;
}

char *parser2(char *tmp, shell_t *shell)
{
    tmp = cat_string(tmp, shell->head->text);
    shell->head = shell->head->next;
    return tmp;
}

parser_t *parser(shell_t *shell)
{
    char *tmp = NULL;

    if (shell == NULL || shell->head->text == NULL)
        return NULL;
    init_struct(shell->parser_tree);
    while (shell->head->token != END) {
        if (shell->head->token == IDENTIFIERS) {
            tmp = parser2(tmp, shell);
            continue;
        }
        shell = add_value(tmp, shell);
        free(tmp);
        tmp = NULL;
        shell->save_token = shell->head->token;
        shell->head = shell->head->next;
    }
    shell = add_value(tmp, shell);
    return shell->parser_tree;
}
