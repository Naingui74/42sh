/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_isalpha.c
*/

int my_isalpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    return 84;
}
