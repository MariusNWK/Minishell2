/*
** EPITECH PROJECT, 2021
** main
** File description:
** mysh
*/

#include "include/my.h"

int main(int ac, char **av, char **env)
{
    storage_t storage = {NULL, 0, 0};

    if (error_handling(ac, av, env) == 84) {
        return (84);
    }
    if ((storage.env = alloc_env(env, env)) == NULL) {
        storage.env = alloc_env(env, env);
    }
    my_sh(&storage);
    my_putstr("exit\n");
    free_dbtab(storage.env);
    return (storage.status);
}