/*
** EPITECH PROJECT, 2021
** make_cd
** File description:
** mysh
*/

#include "include/my.h"

void make_cd(char **inputs, storage_t *storage)
{
    int str_nbr = set_str_nbr(inputs) - 1;

    storage->status = 1;
    if (str_nbr > 1) {
        my_puterr("cd: Too many arguments.\n");
        return;
    }
    else if (str_nbr == 0) {
        my_puterr("cd: Too few arguments.\n");
        return;
    }
    storage->status = 0;
    if (chdir(inputs[1]) == -1) {
        my_puterr(inputs[1]);
        my_puterr(": No such file or directory.\n");
        storage->status = 1;
        return;
    }
}