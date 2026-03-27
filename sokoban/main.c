/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "sokoban.h"

char *read_file(char *path)
{
    int fd = 0;
    char *str = NULL;
    struct stat filestat;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, get_msg("error_file_not_openable"), path);
        return NULL;
    } if (stat(path, &filestat) == -1) {
        fputs(get_msg("error_general"), stderr);
        close(fd);
        return NULL;
    } if (filestat.st_size < 3) {
        fputs(get_msg("error_small_file"), stderr);
        close(fd);
        return NULL;
    } if (filestat.st_size > 2147483647) {
        fputs(get_msg("error_big_file"), stderr);
        close(fd);
        return NULL;
    }
    str = malloc(filestat.st_size + 1);
    if (str == NULL) {
        fputs(get_msg("error_memory"), stderr);
        close(fd);
        return NULL;
    }
    if (read(fd, str, filestat.st_size) <= 0) {
        fputs(get_msg("error_file_not_readable"), stderr);
        free(str);
        close(fd);
        return NULL;
    }
    str[filestat.st_size] = '\0';
    close(fd);
    return str;
}

void free_map(char **tab, int size)
{
    while (--size >= 0)
        free(tab[size]);
    free(tab);
}

char **create_map(char *str, int size)
{
    int i = 0;
    int i2 = 0;
    int j = 0;
    char **tab = malloc(sizeof(char*)*(size+1));

    if (tab == NULL)
        return NULL;
    while (str[i+i2] != '\0') {
        if (str[i+i2] != '\n')
            ++i;
        else if (i != 0) {
            tab[j] = strndup(str+i2, i);
            if (tab[j] == NULL) {
                free_map(tab, j);
                return NULL;
            }
            ++j;
            i2 += i+1;
            i = 0;
        }
        else
            ++i2;
    }
    if (i != 0) {
        tab[j] = strndup(str+i2, i);
        if (tab[j] == NULL) {
            free_map(tab, j);
            return NULL;
        }
        ++j;
    }
    tab[j] = NULL;
    return tab;
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        fprintf(stderr, get_msg("error_parameter"), ac);
        return 1;
    }
    if (ac == 3) {
        set_lang(av[2]);
    }

    char *str = read_file(av[1]);
    if (str == NULL)
        return 1;
    int i = check_str(str);
    if (i == -1) {
        free(str);
        return 1;
    }
    char **map = create_map(str, i);
    free(str);
    if (map == NULL) {
        fputs(get_msg("error_memory"), stderr);
        free_map(map, i);
        return 1;
    }
    int rv = screen(map);
    free_map(map, i);
    return rv;
}
