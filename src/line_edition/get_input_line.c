/*
** EPITECH PROJECT, 2024
** B-PSU-200-BDX-2-1-42sh-aaron.groux
** File description:
** get_input_line
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>
#include "../../include/minishell.h"
#include "../../include/my.h"

char *get_input_line(const char *prompt)
{
    int buffer_index = 0;
    int cursor_position = 0;
    char *buffer = NULL;
    char *result = NULL;

    enable_raw_mode();
    atexit(disable_raw_mode);
    buffer = malloc(MAX_BUFFER_SIZE);
    while (1) {
        result = NULL;
        if (result != NULL) {
            return result;
        }
    }
}
