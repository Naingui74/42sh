/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** function my_show_word_array
*/

#include <string.h>
#include "my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        my_putchar('[');
        my_putstr(tab[i]);
        my_putchar(']');
    }
    my_putchar('\n');
}
