#ifndef LIBMX_H
#define LIBMX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s, int potok);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n, int potok);

double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);

char *mx_itoa(int number);

int mx_strlen(const char *s);
void mx_swap_char(char *c1, char *c2);
void mx_str_reverse(char *s);

void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);

char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);

int mx_strncmp(const char *s1, const char *s2, size_t n);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);

char *mx_strstr(const char *haystack, const char *needle);

int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);

char *mx_strnew(const int size);

char *mx_strtrim(const char *str);
char **mx_strsplit(const char *s, char c);

char *mx_strjoin(char *s1, char *s2);
char *mx_file_to_str(const char *file);

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);

int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

bool mx_isspace(int c);
int mx_isalpha(char alpha);
int mx_isdigit(char dig);
int mx_atoi(const char *str);
int get_len(const char *file);

#endif
