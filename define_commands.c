/*
** EPITECH PROJECT, 2021
** define commands
** File description:
** define the commands separated by ; | and > >> < <<
*/

#include "include/my.h"

int define_nbr_of_commands(char *line)
{
    int nbr_of_commands = 1;
    int separator = 0;
    int char_found = 0;

    for (int i = 0; line[i] != '\n'; i++) {
        if (line[i] == ';' && char_found)
            separator = 1;
        if (line[i] >= 33 && line[i] <= 126 &&
            line[i] != ';' && separator && char_found) {
            nbr_of_commands++;
            separator = 0;
        }
        if (line[i] >= 33 && line[i] <= 126 && line[i] != ';')
            char_found = 1;
    }
    return (nbr_of_commands);
}

int *define_sizes_commands(char *line, int nbr_of_commands)
{
    int *sizes = malloc(sizeof(int) * nbr_of_commands);

    for (int k = 0, cmd = 0, size = 0; cmd < nbr_of_commands; cmd++, size = 0) {
        while (line[k] == ' ' || line[k] == ';' || line[k] == '\t')
            k++;
        while (line[k] != ';' && line[k] != '\n') {
            size++;
            k++;
        }
        sizes[cmd] = size;
    }
    return (sizes);
}

void define_commands(char *line, storage_t *storage)
{
    int nbr_of_commands = define_nbr_of_commands(line);
    int *sizes = define_sizes_commands(line, nbr_of_commands);
    char **commands = malloc(sizeof(char *) * (nbr_of_commands + 1));

    for (int i = 0, k = 0; i < nbr_of_commands; i++) {
        commands[i] = malloc(sizeof(char) * (sizes[i] + 2));
        while (line[k] == ' ' || line[k] == ';' || line[k] == '\t')
            k++;
        for (int j = 0; j < sizes[i]; j++, k++)
            commands[i][j] = line[k];
        commands[i][sizes[i]] = '\n';
        commands[i][sizes[i] + 1] = '\0';
    }
    commands[nbr_of_commands] = NULL;
    for (int i = 0; i < nbr_of_commands; i++)
        execute_command(commands[i], storage);
    free(sizes);
    free(commands);
    free(line);
}