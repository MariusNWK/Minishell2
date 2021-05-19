/*
** EPITECH PROJECT, 2021
** execute_command
** File description:
** execute the command in argument
*/

#include "include/my.h"

void simple_command(char *command, storage_t *storage)
{
    char **inputs = define_inputs(command);

    if (inputs) {
        find_builtins(inputs, storage);
        free_dbtab(inputs);
    }
    else storage->status = 139;
}

int is_a_pipe(char *command)
{
    for (int i = 0; command[i]; i++) {
        if (command[i] == '|')
            return (1);
    }
    return (0);
}

void pipe_command(char *command, storage_t *storage)
{
    int check_return = is_pipe_correct(command, storage);

    if (check_return == 1) {
        make_pipe(command, storage);
    }
    else if (check_return == 0) {
        storage->status = 1;
        my_puterr("Invalid null command.\n");
        free(command);
    }
}

int is_a_redirection(char *command)
{
    for (int i = 0; command[i]; i++) {
        if (command[i] == '>' || command[i] == '<')
            return (1);
    }
    return (0);
}

void execute_command(char *command, storage_t *storage)
{
    if (is_a_redirection(command))
        return (redirection_command(command, storage));
    if (is_a_pipe(command) && my_strlen(command) > 0)
        pipe_command(command, storage);
    else
        simple_command(command, storage);
}