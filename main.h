#ifndef MAIN_H
#define MAIN_H

void print_env(char **env);
size_t _strlen(const char *str);
char *_getenv(char **env, const char *keyword);
int _setenv(char **env, char *keyword, char *value);
int buildpath(const char *str1, const char *str2, char *result, size_t buffer_size);
int run_command(int ac, char **av,  int interactive);
int run_file(int ac, char **av, int fd);
int read_command(char **lineptr, size_t *n, int fd);
void prompt(void);
int _strchr(const char *str, int ch);
int _strcpy(char *dest, const char *src, int buffer_size);
int fork_command(char *lineptr, char **av, char **env);
char *_strdup(const char *str);
int command_exists(const char *command, char *command_path, char **env);
int _printf(const char *format, ...);

typedef int (*InternalFunction)(int, char **, char **);

struct FunctionEntry
{
	const char *name;
	InternalFunction function;
};
InternalFunction is_internal_command(char *name);
int internal_exit(int, char **av, char **env);
int internal_unsetenv(int ac, char **av, char **env);
int internal_setenv(int ac, char **av, char **env);
int internal_env(int, char **av, char **env);
int internal_cd(int ac, char **av, char **env);
int internal_alias(int ac, char **av, char **env);
int _strcmp(const char *s1, const char *s2);
void free_av(char **av);
int _atoi(const char *str);
int process_command(char **av, int new_ac, char **new_av);
int process_command_line(char **av, char *lineptr);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *get_token(char *str, const char *delim);

char **get_shell_env(void);
char **copy_env(char **env);
void  free_env(char **env);
int add_env(char **env, char *env_variable);
char *_trim(char *str);
char* _itoa(int number);
int get_last_status(void);
char *replace_variable(char *var);


#endif
