/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_myprintf.c
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    char str [6];

    strcpy(str, "world");
    my_printf("Hello %s\n", str);

    // ASSERT
    cr_assert_stdout_eq_str("Hello world\n");
}

Test(my_printf, multiple_args, .init = redirect_all_std)
{
    int nb = 21;

    my_printf("If you multiple %d by %d, the result is %i.\n", nb, 2, nb * 2);

    // ASSERT
    cr_assert_stdout_eq_str("If you multiple 21 by 2, the result is 42.\n");
}

Test(my_printf, percent, .init = redirect_all_std)
{
    char str [8];
    
    strcpy(str, "Epitech");
    my_printf("The word %%%s%% has %i characters.\n", str, strlen(str));

    // ASSERT
    cr_assert_stdout_eq_str("The word %Epitech% has 7 characters.\n");
}

Test(my_printf, negative_number, .init = redirect_all_std)
{
    my_printf("number = %d", -789);

    // ASSERT
    cr_assert_stdout_eq_str("number = -789");
}

Test(my_printf, d_flag, .init = redirect_all_std)
{
    my_printf("int: %d", 789);
    cr_assert_stdout_eq_str("int: 789");
}

Test(my_printf, i_flag, .init = redirect_all_std)
{
    my_printf("int: %i", 6);
    cr_assert_stdout_eq_str("int: 6");
}

Test(my_printf, s_flag, .init = redirect_all_std)
{
    my_printf("str: %s", "Hello world!");
    cr_assert_stdout_eq_str("str: Hello world!");
}

Test(my_printf, c_flag, .init = redirect_all_std)
{
    my_printf("char: %c", 'Z');
    cr_assert_stdout_eq_str("char: Z");
}

Test(my_printf, percent_flag, .init = redirect_all_std)
{
    my_printf("percent: %%");
    cr_assert_stdout_eq_str("percent: %");
}

Test(my_printf, o_flag, .init = redirect_all_std)
{
    my_printf("signed octal: %o", 4206324);
    cr_assert_stdout_eq_str("signed octal: 20027364");
}

Test(my_printf, neg_o_flag, .init = redirect_all_std)
{
    my_printf("negative signed octal: %o", -4206324);
    cr_assert_stdout_eq_str("negative signed octal: 37757750414");
}

Test(my_printf, u_flag, .init = redirect_all_std)
{
    my_printf("unsigned decimal int: %u", 4000000000);
    cr_assert_stdout_eq_str("unsigned decimal int: 4000000000");
}

Test(my_printf, neg_u_flag, .init = redirect_all_std)
{
    my_printf("negative unsigned decimal int: %u", -4294967293);
    cr_assert_stdout_eq_str("negative unsigned decimal int: 3");
}

Test(my_printf, f_flag, .init = redirect_all_std)
{
    my_printf("float: %f", 5.2);
    cr_assert_stdout_eq_str("float: 5.200000");
}

Test(my_printf, x_flag, .init = redirect_all_std)
{
    my_printf("unsigned hexa int: %x", 10476856);
    cr_assert_stdout_eq_str("unsigned hexa int: 9fdd38");
}

Test(my_printf, neg_x_flag, .init = redirect_all_std)
{
    my_printf("negative unsigned hexa int: %x", -4000000000);
    cr_assert_stdout_eq_str("negative unsigned hexa int: 1194d800");
}

Test(my_printf, X_flag, .init = redirect_all_std)
{
    my_printf("unsigned hexa int (capital): %X", 10476856);
    cr_assert_stdout_eq_str("unsigned hexa int (capital): 9FDD38");
}

Test(my_printf, neg_X_flag, .init = redirect_all_std)
{
    my_printf("negative unsigned hexa int (capital): %X", -4000000000);
    cr_assert_stdout_eq_str("negative unsigned hexa int (capital): 1194D800");
}

Test(my_printf, error_handling, .init = redirect_all_std)
{
    my_printf("this is a test inter%yrupted");
    cr_assert_stdout_eq_str("this is a test inter%yrupted");
}

Test(my_printf, error_returns, .init = redirect_all_std)
{
    int output_error = my_printf("error = this is a test inter%yrupted");
    int output_no_error = my_printf("no_error = this is a test interrupted");

    if (output_error == 84 && output_no_error != 84) {
        cr_assert(true);
    } else {
        cr_assert(false);
    }
}



