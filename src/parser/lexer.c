/*
** EPITECH PROJECT, 2024
** Lexcer-Parser
** File description:
** pipe.c
*/

#include "lexer.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_a_pipe(shell_t *shell, lexer_t *new)
{
    if (new == NULL)
        return 84;
    if (shell->input[shell->cursor] == '|') {
        new->text = "|";
        new->token = PIPES;
        new->len = 1;
        shell->cursor += 1;
        shell->cursor_text = shell->cursor;
        if (shell->input[shell->cursor] == '|') {
            new->text = "||";
            new->token = OR;
            new->len = 1;
            shell->cursor += 1;
            shell->cursor_text = shell->cursor;
        }
        return 0;
    }
    return 1;
}

int is_a_semicolons(shell_t *shell, lexer_t *new)
{
    if (new == NULL)
        return 84;
    if (shell->input[shell->cursor] == ';') {
        new->text = ";";
        new->token = SEMICOLONS;
        new->len = 1;
        shell->cursor += 1;
        shell->cursor_text = shell->cursor;
        return 0;
    }
    return 1;
}

int is_a_and(shell_t *shell, lexer_t *new)
{
    if (new == NULL)
        return 84;
    if (shell->input[shell->cursor] == '&') {
        shell->cursor++;
        shell->cursor_text = shell->cursor;
        if (shell->input[shell->cursor] == '&') {
            new->text = "&&";
            new->token = AND;
            new->len = 1;
            shell->cursor += 1;
            shell->cursor_text = shell->cursor;
            return 0;
        }
    }
    return 1;
}

static
int take_input_alpha(shell_t *shell, lexer_t *new)
{
    if (new == NULL)
        return 84;
    if (do_quote(shell, new) == 0)
        return 0;
    if (IS_GOOD(shell->input[shell->cursor]) == 0 && shell->status_q == 0) {
        for (; IS_GOOD(shell->input[shell->cursor]) == 0; shell->cursor++);
        new->text = strndup(&shell->input[shell->cursor_text],
                            shell->cursor - shell->cursor_text);
        new->token = IDENTIFIERS;
        new->len = shell->cursor - shell->cursor_text;
        shell->cursor_text = shell->cursor;
        return 0;
    }
    return 84;
}

static
int parse_lexer(shell_t *shell, lexer_t *new)
{
    while (shell->input[shell->cursor] == ' ') {
        shell->cursor++;
        shell->cursor_text = shell->cursor;
    }
    if (is_a_pipe(shell, new) == 0)
        return 0;
    if (take_input_alpha(shell, new) == 0)
        return 0;
    if (is_a_semicolons(shell, new) == 0)
        return 0;
    if (is_a_and(shell, new) == 0)
        return 0;
    if (shell->input[shell->cursor] == '\0')
        return 84;
    shell->cursor++;
    shell->cursor_text = shell->cursor;
    return 84;
}

static
void init_last_node(lexer_t *tmp)
{
    if (tmp == NULL)
        return;
    tmp->next = malloc(sizeof(lexer_t));
    tmp->next->text = NULL;
    tmp->next->token = END;
    tmp->next->len = 0;
    tmp->next->next = NULL;
}

static
int lexer(shell_t *shell)
{
    lexer_t *new = NULL;
    lexer_t *tmp = NULL;

    while (shell->input[shell->cursor] != '\0') {
        new = malloc(sizeof(lexer_t));
        if (parse_lexer(shell, new) == 84)
            return 84;
        if (tmp == NULL)
            shell->head = new;
        else
            tmp->next = new;
        tmp = new;
    }
    init_last_node(tmp);
    return 0;
}

static
int init_shell(shell_t *shell, char *line)
{
    if (shell == NULL || line == NULL)
        return 84;
    shell->input = strdup(line);
    shell->input = clean_str(shell->input);
    shell->cursor = 0;
    shell->cursor_text = 0;
    shell->head = NULL;
    shell->is_first = true;
    shell->parser_tree = NULL;
    shell->save_token = END;
    shell->status_q = 0;
    return 0;
}

parser_t *lexer_parser(char *line)
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (init_shell(shell, line) == 84)
        return NULL;
    shell->parser_tree = malloc(sizeof(parser_t));
    if (shell->parser_tree == NULL)
        return NULL;
    if (lexer(shell) == 84)
        return NULL;
    if (IS_GOOD(shell->head->text[0]) == 1)
        return NULL;
    parser(shell);
    return shell->parser_tree;
}
