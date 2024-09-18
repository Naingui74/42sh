/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** function my_putstr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i = i + 1) {
        write(1, &str[i], 1);
    }
    return 0;
}
