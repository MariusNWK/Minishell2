/*
** EPITECH PROJECT, 2021
** make_setenv
** File description:
** mysh
*/

#include "include/my.h"

char *set_env_arg(char **inputs, int str_nbr)
{
    char *tmp = my_strcat(inputs[1], "=");
    char *tmp_value;

    if (str_nbr == 1) {
        return (tmp);
    }
    tmp_value = my_strcat(tmp, inputs[2]);
    free(tmp);
    return (tmp_value);
}

int set_str_nbr(char **env)
{
    int len = 0;

    while (*env) {
        env++;
        len++;
    }
    return (len);
}

int does_begin_by_letter(char *arg)
{
    if ((arg[0] >= 65 && arg[0] <= 90) ||
        (arg[0] >= 97 && arg[0] <= 122)) {
        return (1);
    }
    return (0);
}

void make_setenv(storage_t *storage, char **inputs)
{
    char *n_arg;
    int str_nbr = set_str_nbr(inputs) - 1;
    char *use_make_env[] = {"env", NULL};

    storage->status = 1;
    if (str_nbr > 2) {
        my_puterr("setenv: Too many arguments.\n");
        return;
    }
    if (str_nbr == 0) {
        storage->status = 0;
        make_env(storage->env, use_make_env);
        return;
    }
    if (does_begin_by_letter(inputs[1]) == 0) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return;
    }
    n_arg = set_env_arg(inputs, str_nbr);
    def_new_env(storage, inputs[1], n_arg);
    storage->status = 0;
}