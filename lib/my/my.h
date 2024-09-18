/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Pool day 9
** Task 02
*/

#ifndef MY_H
    #define MY_H

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
void my_isneg(int nb);
int my_putnbr(long nb);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_strlen(char const *str);
void my_show_word_array(char **tab);
int my_printf(const char *format, ...);
int my_arrlen(char **tab);
char *my_strdup(char const *src);
int my_isalpha(char c);
int my_isalphanum(char c);
char *remove_first_char(char *str);
char *clean_all_str(char *str);

// CUSTOM FUNCTION
int my_stderr(char const *str);
int my_nbrlen(int nb);
int my_puthex(unsigned int nb);
int my_puthex_capital(unsigned int nb);
int my_putoctal(unsigned int nb);
int my_putptr(unsigned long nb);
int my_put_udecimal(unsigned int nb);
int my_putfloat(double nb, int precision);
char **split(char *str, char *separators);
char **my_str_to_word_array(char const *str, char **separator);

#endif
