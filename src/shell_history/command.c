/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** command.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"
#include <string.h>

void close_file2(FILE *fptr2, FILE *fptr_cpy2)
{
    fclose(fptr_cpy2);
    fclose(fptr2);
}

char *stock_history2(all_t *all)
{
    FILE *fptr2;
    char c = '\0';
    int i = 0;
    char *buff = NULL;
    int nb = count_char();

    buff = malloc(sizeof(char) * nb + 1);
    fptr2 = fopen("command", "r");
    if (fptr2 == NULL)
        return NULL;
    while (1) {
        c = fgetc(fptr2);
        if (c == EOF)
            break;
        buff[i] = c;
        i++;
    }
    buff[i] = '\0';
    fclose(fptr2);
    return buff;
}

void exclamation(all_t *all)
{
    char *end = NULL;
    long num = strtol(all->shell.cmd[0] + 1, &end, 10);
    char *buff = stock_history2(all);
    char **tab_cmd = split(buff, "\n");
    char *cmd = tab_cmd[num];

    printf("%s\n", cmd);
}
