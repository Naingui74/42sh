/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** quote.c
*/

#include "lexer.h"
#include "my.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_quote(shell_t *shell, int i)
{
    for (; shell->input[i] != '\0'; i++)
        if (shell->input[i] == '"')
            return 0;
    my_putstr("Unmatched '\"'.\n");
    shell->status_q = 84;
    return 84;
}

int do_quote(shell_t *shell, lexer_t *new)
{
    if (IS_QUOTE(shell->input[shell->cursor]) == 1) {
        shell->cursor++;
        shell->cursor_text = shell->cursor;
        if (check_quote(shell, shell->cursor) == 84)
            return 84;
        for (; IS_QUOTE(shell->input[shell->cursor]) == 0; shell->cursor++);
        new->text = strndup(&shell->input[shell->cursor_text],
                            shell->cursor - shell->cursor_text);
        new->token = IDENTIFIERS;
        new->len = shell->cursor - shell->cursor_text;
        shell->cursor++;
        shell->cursor_text = shell->cursor;
        return 0;
    }
    return 1;
}
