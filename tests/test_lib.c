/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_lib.c
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(my_strlen, my_strlen, .init=cr_redirect_stdout)
{
    char const *str = "salut";
    cr_expect_eq(my_strlen(str), 5);
}

Test(my_putchar, my_putchar, .init=cr_redirect_stdout)
{
    char const c = '.';
    my_putchar(c);
    cr_assert_stdout_eq_str(".");
}

Test(my_putstr, my_putstr, .init=cr_redirect_stdout)
{
    char const *str = "Hello World!";
    my_putstr(str);
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_strcmp, my_strcmp)
{
    char const *str1 = "hello";
    char const *str2 = "hello";
    cr_expect_eq(my_strcmp(str1, str2), 0);
}
