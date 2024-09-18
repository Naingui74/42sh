/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** flag.c
*/

#include "../../include/my.h"
#include "../../include/minishell.h"
#include <string.h>
#include <time.h>

void clear_history(void)
{
    FILE *fptr;

    fptr = fopen("history", "w");
    if (fptr == NULL) {
        return;
    }
    fclose(fptr);
}

void print_history(void)
{
    FILE *fptr;
    char c;

    fptr = fopen("history", "r");
    if (fptr == NULL)
        return;
    while (1) {
        c = fgetc(fptr);
        if (c == EOF)
            break;
        putchar(c);
    }
    fclose(fptr);
}

void print_reverse(all_t *all)
{
    init_history(all);
    for (int i = tab_len(all->history.tab) - 1; i >= 0; i --) {
        printf("%s\n", all->history.tab[i]);
    }
}

int count_char(void)
{
    FILE *fptr;
    int i = 0;
    char c;

    fptr = fopen("history", "r");
    while (1) {
        c = fgetc(fptr);
        i++;
        if (c == EOF) {
            return i;
        }
    }
    fclose(fptr);
}

int tab_len(char **tab)
{
    int counter = 0;

    for (int i = 0; tab[i] != NULL; i += 1) {
        counter++;
    }
    return counter;
}
