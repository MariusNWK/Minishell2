/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** mysh
*/

#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void my_putchar(char);
int my_strlen(char *);
void my_putstr(char *);
int is_same_str(char *, char *);
int my_getnbr(char const *);
char *my_strdup(char const *);
void my_puterr(char *);
char *my_strcat(char *, char *);
char *file_reader(char const *);

////////////////////////////////////////////////////////////

int error_handling(int, char **, char **);

////////////////////////////////////////////////////////////

typedef struct storage
{
    char **env;
    int status;
    int exit;
} storage_t;

////////////////////////////////////////////////////////////

void my_sh(storage_t *);
void define_commands(char *, storage_t *);
void execute_command(char *, storage_t *);
void redirection_command(char *, storage_t *);
void make_redirection(char *, storage_t *);
void simple_right_redirect(char *, storage_t *);
void double_right_redirect(char *, storage_t *);
void simple_left_redirect(char *, storage_t *);
void double_left_redirect(char *, storage_t *);
char *define_file_name(char *, char);
char *redefine_command(char *, char *, char);
int is_pipe_correct(char *, storage_t *);
void make_pipe(char *, storage_t *);
void exec_pipe(char *, char *, storage_t *);
void display_prompt(void);
void find_builtins(char **, storage_t *);
void make_cd(char **, storage_t *);
void make_command(char *, char **, storage_t *);
void make_setenv(storage_t *, char **);
void make_unsetenv(storage_t *, char **);
int make_env(char **, char **);
int make_exit(char *, char **, storage_t *);
void make_exe(char *, char **, storage_t *);

////////////////////////////////////////////////////////////

char **alloc_env(char **, char **);
void free_dbtab(char **);
int check_try_execute(char *);
int set_str_nbr(char **);
char **set_dirs(char **);
int count_paths_nbr(char *);
char *add_path(char *, char **);
char **define_inputs(char *);
void def_new_env(storage_t *, char *, char *);

////////////////////////////////////////////////////////////