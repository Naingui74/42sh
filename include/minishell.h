/*
** EPITECH PROJECT, 2023
** repo_settingup
** File description:
** struct.h
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "lexer.h"
    #define OK 0
    #define KO 84
    #define MAX_BUFFER_SIZE 1024

typedef struct history_s {
    int size;
    char *buff;
    char **tab;
    char **tab2;
    char *cmd;
    char **tab_cmd;
} history_t;

typedef struct variables_s {
    int index;
    char *variable;
    char *value;
    struct variables_s *next;
} variables_t;

typedef struct {
    char *input;
    char **cmd;
    char *path;
    char **concat_path;
    char **my_env;
    char *home;
    char *pwd;
    char *old_pwd;
    int my_status;
    char *input2;
    variables_t *variables;
    char *buffer;
    int history;
    int repeat_counter;
} type_t;

typedef struct node_s {
    char *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct linked_list_s {
    node_t *first;
    node_t *last;
} linked_list_t;

typedef struct redirect_s {
    char *redirect_sup;
    char *redirect_supsup;
    char *redirect_left;
    char *redirect_leftleft;
    int superior_type;
    int inferior_type;
    int pipe_type;
    char *pipe;
    char **pipe_arr;
} redirect_t;

typedef struct {
    type_t shell;
    linked_list_t list;
    node_t node;
    redirect_t redirect;
    parser_t *lexer;
    history_t history;
} all_t;

//EXECUTION
int minishell1(all_t *all);
int execute_command(all_t *all);
char *path_loop(all_t *all, char *str);
int execute_binary(all_t *all);
int concat_path(all_t *all);
int concat_home(all_t *all);
char *remove_first_space(char *str);
void handle_command(all_t *all, char **env);
int call_exec(all_t *all);
int handle_child_exit_status(all_t *all, int status);
int command_in_loop(all_t *all, char *cmd);

//BUILTINS
int is_builtin(all_t *all);
int my_env(all_t *all);
char **copy_env(all_t *all, char **env);
char *my_getenv(all_t *all, char *name);
int my_cd(all_t *all);
int print_pwd(all_t *all);
int my_cd_handler(all_t *all);
void execute_builtin(all_t *all);
int my_unsetenv(all_t *all);
int my_setenv_handler(all_t *all);
int my_setenv(all_t *all, char *name);

//LOOP
int loop_semicolons(all_t *all);
//ALIAS

//PARSING
void redirect_superior(all_t *all, int *stdout_copy);
void redirect_superior2(all_t *all, int *stdout_copy);
int superior_redirect(all_t *all);
int inferior_redirect(all_t *all);
void redirect_inferior(all_t *all, int *stdin_copy);
void redirect_inferior2(all_t *all, int *stdin_copy);
void handle_redirect(all_t *all);
void find_all(all_t *all);
void restore_stdout_stdin(all_t *all, int stdout_copy, int stdin_copy);
int find_pipe(all_t *all);
int pipe_action(all_t *all);
void take_after_pipe(all_t *all, int *i);
int variables(all_t *all);
parser_t *lexer_parser(char *line);

//LINKED LIST
linked_list_t tab_to_linked_list(all_t *all);
int printf_list(all_t *all);
void modify_node_value(all_t *all, char *name, char *value);
char *concatenate_name_value(char *name, char *value);
node_t *find_node_with_name(all_t *all, char *name);
char **linked_list_to_tab(all_t *all);
void add_node(all_t *all, char *value);

//LINE EDITION
void enable_raw_mode(void);
void disable_raw_mode(void);
char *get_input_line(const char *prompt);

//FREE
void free_struct(all_t *all);
void free_all(all_t *all);

//HISTORY
void write_in_history(all_t *all);
void print_history(void);
void clear_history(void);
int read_file(all_t *all, history_t *history);
void print_reverse(all_t *all);
int take_index_in_tab(char **tab);
void exclamation(all_t *all);
void write_command(all_t *all);
char *remove_enter(all_t *all, char *str);

//UTILS
void close_file(FILE *fptr, FILE *fptr_cpy);
void close_file2(FILE *fptr, FILE *fptr_cpy);
void init_history(all_t *all);
int tab_len(char **tab);

//STOCK HISTORY
char *stock_history2(all_t *all);
char *stock_history(all_t *all);
int count_char(void);

void check_path_not_null(all_t *all);

#endif
