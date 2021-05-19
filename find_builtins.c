/*
** EPITECH PROJECT, 2021
** find_builtins
** File description:
** mysh
*/

#include "include/my.h"

int is_exe_file(char *file)
{
    struct stat st;

    if (stat(file, &st) == -1) {
        return (0);
    }
    if (st.st_mode != 33277) {
        return (0);
    }
    return (1);
}

int is_command_found(char **path, int i, char *command)
{
    DIR *dir;
    struct dirent *sd;
    int is = 0;

    dir = opendir(path[i]);
    if (dir)
        while ((sd = readdir(dir)) != NULL)
            if (is_same_str(sd->d_name, command)) {
                is = 1;
                break;
            }
    closedir(dir);
    return (is);
}

int is_bin_command(char *command, char **env)
{
    char **path;
    int paths_nbr = 0;
    int is = 0;

    if ((path = set_dirs(env)) == NULL)
        return (0);
    paths_nbr = set_str_nbr(path);
    for (int i = 0; i < paths_nbr && is == 0; i++) {
        if (is_command_found(path, i, command)) {
            is = 1;
        }
    }
    for (int i = 0; i < paths_nbr; i++)
        free(path[i]);
    free(path);
    return (is);
}

void unknown_command(char *command, storage_t *storage)
{
    struct stat st;

    storage->status = 1;
    if (stat(command, &st) == 0 && check_try_execute(command) == 1) {
        my_puterr(command);
        my_puterr(": Permission denied.\n");
        return;
    }
    my_puterr(command);
    my_puterr(": Command not found.\n");
}

void find_builtins(char **inputs, storage_t *storage)
{
    if (is_same_str(inputs[0], "cd"))
        return (make_cd(inputs, storage));
    if (is_same_str(inputs[0], "setenv"))
        return (make_setenv(storage, inputs));
    if (is_same_str(inputs[0], "unsetenv"))
        return (make_unsetenv(storage, inputs));
    if (is_same_str(inputs[0], "env")) {
        storage->status = make_env(storage->env, inputs);
        return;
    }
    if (is_same_str(inputs[0], "exit")) {
        storage->status = make_exit(inputs[0], inputs, storage);
        return;
    }
    if (is_exe_file(inputs[0]))
        return (make_exe(inputs[0], inputs, storage));
    if (is_bin_command(inputs[0], storage->env))
        return (make_command(inputs[0], inputs, storage));
    unknown_command(inputs[0], storage);
}