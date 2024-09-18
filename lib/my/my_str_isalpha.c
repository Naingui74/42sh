/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** function my_str_isalpha
*/

#include <stddef.h>

int my_str_isalpha(char const *str)
{
    int nonalphanumeric = 0;

    if (str[0] == '\0') {
        return 84;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))) {
            nonalphanumeric = 1;
        }
    }
    if (nonalphanumeric >= 1) {
        return 84;
    } else {
        return 0;
    }
}
