/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_cd.c
*/

#include "../../include/minishell.h"
#include "../../include/my.h"

int cd_error_handling(all_t *all, char *path)
{
    struct stat dir_stat;

    if (all->shell.cmd[0] != NULL && all->shell.cmd[1] != NULL &&
    all->shell.cmd[2] != NULL) {
        my_stderr("cd: Too many arguments.\n");
        return all->shell.my_status;
    }
    if (stat(path, &dir_stat) == -1) {
        my_stderr(path);
        my_stderr(": No such file or directory.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    if (!S_ISDIR(dir_stat.st_mode)) {
        my_putstr(path);
        my_stderr(": Not a directory.\n");
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    return 0;
}

int cd_to_oldpwd(all_t *all)
{
    char *oldpwd = my_getenv(all, "OLDPWD");

    if (cd_error_handling(all, oldpwd) == 1)
        all->shell.my_status = 1;
    if (chdir(oldpwd) == -1) {
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    return 0;
}

int cd_to_dir(all_t *all)
{
    char *dir = all->shell.cmd[1];

    if (dir == NULL || my_strcmp("~", dir) == 0)
        dir = my_getenv(all, "HOME");
    if (cd_error_handling(all, dir) == 1) {
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    if (chdir(dir) == -1) {
        all->shell.my_status = 1;
        return all->shell.my_status;
    }
    return 0;
}

int concat_home_path(all_t *all)
{
    char *home = NULL;
    char *concat_path = NULL;
    char *cut_str = remove_first_char(all->shell.cmd[1]);

    if (my_getenv(all, "HOME") != NULL)
        home = my_getenv(all, "HOME");
    concat_path = malloc(sizeof(char) * (my_strlen(home) +
    my_strlen(cut_str) + 1));
    if (!concat_path)
        return 84;
    my_strcpy(concat_path, home);
    my_strcat(concat_path, cut_str);
    if (cd_error_handling(all, concat_path) == 1)
        all->shell.my_status = 1;
    chdir(concat_path);
    free(concat_path);
    return 0;
}

int my_cd(all_t *all)
{
    if (all->shell.cmd[1] != NULL && my_strcmp(all->shell.cmd[1], "-") == 0)
        return cd_to_oldpwd(all);
    else if (all->shell.cmd[1] != NULL &&
    (all->shell.cmd[1][0] == '~') && all->shell.cmd[1][1] != '\0')
        return concat_home_path(all);
    else
        return cd_to_dir(all);
}
