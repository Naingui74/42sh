/*
** EPITECH PROJECT, 2024
** Lexcer-Parser
** File description:
** lexcer.h
*/

#ifndef LEXER_H_
    #define LEXER_H_
    #define IS_QUOTE(c) (c == '"')
    #define IS_PIPE(c) (c == '|')
    #define IS_SM(c) (c == 59)
    #define IS_AND(c) (c == '&')
    #define IS_OPE(c) (IS_PIPE(c) || IS_SM(c) || IS_AND(c))
    #define IS_GOOD(c) ((IS_OPE(c) || (c == ' ') || (c == '\0')) ? (1) : (0))
    #include <stddef.h>
    #include <stdbool.h>

typedef enum lexer_enum {
    IDENTIFIERS,
    SEMICOLONS,
    PIPES,
    AND,
    OR,
    END,
}lexer_enum_t;

typedef struct lexer_s {
    lexer_enum_t token;
    char *text;
    size_t len;
    struct lexer_s *next;
}lexer_t;

typedef struct {
    char *cmd;
}pipe_t;

typedef struct {
    pipe_t **pipe;
    int size_pipe;
}or_t;

typedef struct {
    or_t **or_tab;
    int size_or;
}and_t;

typedef struct {
    and_t **and_tab;
    int size_and;
}semicolons_t;

typedef struct {
    semicolons_t **sm;
    int size_sm;
}parser_t;

typedef struct shell_s {
    char *input;
    int cursor;
    int cursor_text;
    lexer_t *head;
    parser_t *parser_tree;
    bool is_first;
    lexer_enum_t save_token;
    int status_q;
}shell_t;

char *clean_str(char *str);
parser_t *parser(shell_t *lexer);

parser_t *check_semicolons(parser_t *tree, char *tmp);
parser_t *check_and(parser_t *tree, char *tmp);
parser_t *check_or(parser_t *tree, char *tmp);
parser_t *check_pipe(parser_t *tree, char *tmp);

int do_quote(shell_t *shell, lexer_t *new);
int check_quote(shell_t *shell, int i);

#endif
