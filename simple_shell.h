#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*
 * File: simple_shell.h
 * Author: Oniya Olaiya and Valrite Hachi
 * Description: Header file for the simple shell program.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include "string_utils.h"
#include <limits.h>

#define BUFFSIZE 1024
#define DELIMITER " \t\r\n\a"

#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

extern char **environ;

/**
 * struct builtin - Represents a built-in command and its function.
 * @command: Name of the built-in command.
 * @fun: Pointer to the command's function.
 *
 * Description: Associates a built-in command's name with its function.
 */

typedef struct builtin
{
	char *command;
	int (*fun)(char **line, int er);
} builtin_t;

int _help(char **cmd, __attribute__((unused)) int last_status);

builtin_t *get_builtin_commands(void);

builtin_t *get_command_functions(void);

void sigint_handler(int sig);

char **tokenize_input(char *user_input);

int process_command(char *line, int counter, FILE *file, char **argv);

int search_and_build_path(char **cmd);

int perform_echo(char **echo_args);

void handle_exit(char **command, char *line_from_file, FILE *file);

void print_command_not_found_error(
	char *command,
	int line_counter,
	char **arguments
);

void print_illegal_number_error(
	char **arguments,
	int counter,
	char **command
);

void exit_shell(
        char **cmd_array,
        char *user_input,
        char **program_argv,
        int execution_count
);

void handle_hashtag(char *buff);

void free_pointers(char **cmd, char *line);

int is_builtin_command(char **cmd);

void display_prompt(void);

int execute_commands_from_file(char *filename, char **argv);

int handle_executable(char **cmd, char *input, int c, char **argv);

int handle_builtin_cmd(char **cmd, int er);

void print_execution_error(char *cmd, char *prog_name, int counter);

/**
 * display_environment - Display current environment.
 * @cmd: Unused parameter.
 * @last_status: Exit status of last command (unused).
 *
 * Description: Placeholder to display the current environment.
 * Return: Always returns 0.
 */

int display_environment(
	__attribute__((unused)) char **cmd,
	__attribute__((unused)) int last_status
);

int input_history(char *user_input);


/**
 * display_history - Display command history.
 * @command: Unused parameter.
 * @last_status: Exit status of last command (unused).
 *
 * Description: Placeholder to display command history.
 * Return: Always returns 0.
 */

int display_history(
	__attribute__((unused)) char **command,
	__attribute__((unused)) int last_status
);

void sigint_handler(int sig);

char *_getenv(char *name);

char *_getline(void);

unsigned int is_delim(char c, const char *delim);

int _help(char **cmd, __attribute__((unused)) int last_status);

int execute_echo(char **cmd, int last_status);

void print_unsigned_int(unsigned int n);

void print_int(int n);

int change_directory(
	char **cmd,
	__attribute__((unused))int last_status
);

/* Memory Allocation Functions */
void *_calloc(unsigned int nmemb, unsigned int size);

void *_realloc(void *ptr, size_t old_size, size_t new_size);

void free_pointers(char **cmd, char *line);

#endif /* SIMPLE_SHELL_H */

