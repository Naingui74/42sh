/*
** EPITECH PROJECT, 2023
** minishell1_test
** File description:
** my_isalphanum.c
*/

int my_isalphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
    (c >= '0' && c <= '9'))
        return 0;
    return 84;
}
