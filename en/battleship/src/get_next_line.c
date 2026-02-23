/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** GNL
*/

#include <stdlib.h>
#include <unistd.h>
#include "../my_printf/print.h"
#include "../navy.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return dest;
}

char *strcut(char *s1, int *i)
{
    char *s2 = malloc(*i + 1);
    int j = 0;

    if (!s2)
        return NULL;
    while (j < *i && (!j || s1[j - 1] != '\n')) {
        s2[j] = s1[j];
        ++j;
    }
    s2[j] = 0;
    while (s1[*i] && (*i <= j || s1[*i] != '\n'))
        ++(*i);
    j += s1[j] == '\n';
    my_strcpy(s1, s1 + j);
    *i -= j;
    return (s2[0] != '\0' ? s2 : NULL);
}

char *str_realloc(char **s1, int size, char *s2)
{
    char *s3 = malloc(size);
    int i = 0;

    if (!s3) {
        free(*s1);
        return NULL;
    }

    if (*s1)
        while ((*s1)[i]) {
            s3[i] = (*s1)[i];
            ++i;
        }
    if (s2)
        while (*s2) {
            s3[i++] = *s2;
            ++s2;
        }
    s3[i] = 0;

    free(*s1);
    *s1 = s3;
    return s3;
}

int read_line(int fd, char **str, int i)
{
    char *buff = malloc(READ_SIZE + 1);
    int byte = 1;
    int slen = my_strlen(*str);

    if (!buff)
        return 0;
    while (byte && *str && (*str)[i] != '\n') {
        byte = read(fd, buff, READ_SIZE);
        if (byte == -1 || slen + byte == 0)
            break;
        if (byte != 0) {
            buff[byte] = '\0';
            slen += byte;
            str_realloc(str, slen + 1, buff);
        }
        while (*str && (*str)[i] != '\0' && (*str)[i] != '\n')
            ++i;
    }
    free(buff);
    return (*str && **str ? i : 0);
}

char *get_next_line(int fd)
{
    static char *str = NULL;
    static int i = 0;

    if (fd != -1 && !str) {
        str = malloc(1);
        if (!str)
            return NULL;
        str[0] = 0;
    }
    if (fd != -1)
        i = read_line(fd, &str, i);
    i += !i && str && *str == '\n';
    if (fd == -1 || i == 0) {
        if (str)
            free(str);
        str = NULL;
        return NULL;
    }
    return strcut(str, &i);
}
