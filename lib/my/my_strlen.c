/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** function my_strlen
*/

#include <stddef.h>
#include <unistd.h>
#include "my.h"

int my_strlen(char const *str)
{
    int counter = 0;

    if (str == NULL) {
        write(2, "error", 6);
        return 84;
    }
    while (str[counter] != '\0') {
        counter += 1;
    }
    return counter;
}
