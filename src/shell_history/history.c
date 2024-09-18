/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"
#include <string.h>
#include <time.h>

char *remove_enter(all_t *all, char *str)
{
    for (int i = 0; all->shell.buffer[i] != '\0'; i += 1) {
        if (all->shell.buffer[i] == '\n')
            all->shell.buffer[i] = '\0';
    }
    return str;
}

void close_file(FILE *fptr, FILE *fptr_cpy)
{
    fclose(fptr_cpy);
    fclose(fptr);
}

static
char *get_current_time(void)
{
    time_t current_time;
    struct tm *local_time;
    static char time_str[6];

    time(&current_time);
    local_time = localtime(&current_time);
    sprintf(time_str, "%02d:%02d", local_time->tm_hour, local_time->tm_min);
    return time_str;
}

static
void write_command_to_history(all_t *all, char *time_str, char c)
{
    FILE *fptr;
    FILE *fptr_cpy;
    int i = 0;

    all->shell.history = 1;
    fptr_cpy = fopen("history", "r");
    fptr = fopen("history", "a");
    while (1) {
        c = fgetc(fptr_cpy);
        if (c == EOF)
            break;
        if (c == '\n')
            i++;
    }
    if (strcmp(all->shell.buffer, "\n") != 0) {
        fprintf(fptr, "    %d  %s   %s\n", i, time_str,
        remove_enter(all, all->shell.buffer));
        i++;
    }
    close_file(fptr, fptr_cpy);
}

void write_in_history(all_t *all)
{
    char c;
    char *time_str = get_current_time();

    write_command_to_history(all, time_str, c);
}

char *stock_history(all_t *all)
{
    FILE *fptr;
    char c = '\0';
    int i = 0;
    char *buff = NULL;
    int nb = count_char();

    buff = malloc(sizeof(char) * nb + 1);
    fptr = fopen("history", "r");
    if (fptr == NULL)
        return NULL;
    while (1) {
        c = fgetc(fptr);
        if (c == EOF)
            break;
        buff[i] = c;
        i++;
    }
    buff[i] = '\0';
    fclose(fptr);
    return buff;
}

void init_history(all_t *all)
{
    all->history.buff = stock_history(all);
    all->history.tab = split(all->history.buff, "\n");
}
