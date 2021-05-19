/*
** EPITECH PROJECT, 2021
** alloc_env
** File description:
** mysh
*/

#include "include/my.h"

char **alloc_env(char **env, char **o_env)
{
    int len = 0;
    char **a_env;

    while (*env) {
        len++;
        env++;
    }
    if ((a_env = malloc(sizeof(char *) * (len + 1))) == NULL) {
        return (NULL);
    }
    for (int i = 0; i <= len; i++, o_env++) {
        if (i == len) {
            a_env[i] = NULL;
        }
        else {
            a_env[i] = my_strdup(*o_env);
        }
    }
    return (a_env);
}