/*
** EPITECH PROJECT, 2023
** my_stderr
** File description:
** print message on
** standard error output
*/

#include <unistd.h>
#include "my.h"

int my_stderr(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return 84;
}
