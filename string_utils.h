#ifndef STRING_UTILS_H
#define STRING_UTILS_H

/*
 * Header File: string_utils.h
 *
 * Description: This file declares a set of string manipulation functions
 * for common operations such as concatenation, conversion, reallocation,
 * length retrieval, and comparison. These functions are designed to be used
 * in C programs for efficient string handling. Each function has its specific
 * purpose and behavior, contributing to a comprehensive suite of utilities
 * for string manipulation.
 */

char *_strcat(char *dest, char *src);

char *_itoa(unsigned int num);

int _putchar(char c);

ssize_t _write(char *str);

int _strncmp(const char *s1, const char *s2, size_t n);

int _atoi(char *s);

void *_realloc(void *ptr, size_t  old_size, size_t new_size);

int _strlen(char *s);

int _isalpha(int _char);

int _strcmp(char *s1, char *s2);

char *_strcpy(char *dest, char *src);

char *_strdup(char *str);

char *_strtok(char *str, const char *delim);
#endif /* STRING_UTILS_H */
