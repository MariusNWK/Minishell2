/*
** EPITECH PROJECT, 2021
** my_sh
** File description:
** mysh
*/

#include "include/my.h"

void handler(int sig)
{
    my_putstr("\n");
    exit(1);
}

int is_line_valid(char *line)
{
    for (int i = 0; line[i] != '\n'; i++)
        if (line[i] != ';' && line[i] != ' ')
            return (1);
    free(line);
    return (0);
}

void my_sh(storage_t *storage)
{
    char *line = NULL;
    size_t len = 0;

    if (isatty(0))
        display_prompt();
    signal(SIGINT, handler);
    if (getline(&line, &len, stdin) == -1) {
        free_dbtab(storage->env);
        free(line);
        if (isatty(0)) {
            my_putstr("exit\n");
            exit(0);
        }
        else exit(storage->status);
    }
    if (my_strlen(line) > 1 && is_line_valid(line))
        define_commands(line, storage);
    if (storage->exit == 0)
        my_sh(storage);
}