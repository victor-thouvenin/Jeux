/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <fcntl.h>
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
        char *emsg = "ERROR: couldn't open \"";
        write(2, emsg, strlen(emsg));
        write(2, path, strlen(path));
        write(2, "\"\n", 1);
        return NULL;
    } if (stat(path, &filestat) == -1) {
        char *emsg = "an error occurred\n";
        write(2, emsg, strlen(emsg));
        close(fd);
        return NULL;
    } if (filestat.st_size < 3) {
        char *emsg = "ERROR: file is too small\n";
        write(2, emsg, strlen(emsg));
        close(fd);
        return NULL;
    } if (filestat.st_size > 2147483647) {
        char *emsg = "ERROR: file is too large\n";
        write(2, emsg, strlen(emsg));
        close(fd);
        return NULL;
    }
    str = malloc(filestat.st_size + 1);
    if (str == NULL) {
        char *emsg = "MEMORY ERROR: an error occurred\n";
        write(2, emsg, strlen(emsg));
        close(fd);
        return NULL;
    }
    if (read(fd, str, filestat.st_size) <= 0) {
        char *emsg = "ERROR: couldn't read file\n";
        write(2, emsg, strlen(emsg));
        free(str);
        close(fd);
        return NULL;
    }
    str[filestat.st_size] = '\0';
    close(fd);
    return str;
}

char **create_map(char *str, int size) {
    int i = 0;
    int i2 = 0;
    int j = 0;
    char **tab = malloc(sizeof(char*)*(size+1));

    while (str[i + i2] != '\0') {
        if (str[i + i2] != '\n')
            ++i;
        else if (i != 0) {
            tab[j] = strndup(str+i2, i);
            if (tab[j] == NULL) {
                while (--j >= 0)
                    free(tab[j]);
                free(tab);
                return NULL;
            }
            ++j;
            i2 += i + 1;
            i = 0;
        }
        else
            ++i2;
    }
    if (i != 0) {
        tab[j] = strndup(str+i2, i);
        if (tab[j] == NULL) {
            while (--j >= 0)
                free(tab[j]);
            free(tab);
            return NULL;
        }
        ++j;
    }
    tab[j] = NULL;
    return tab;
}

int main(int ac, char **av)
{
    char *str;
    char **map;
    int i;
    int j = 0;
    int rv;

    if (ac != 2)
        return 1;
    str = read_file(av[1]);
    if (str == NULL)
        return 1;
    i = check_str(str);
    if (i == -1) {
        free(str);
        return 1;
    }
    map = create_map(str, i);
    free(str);
    rv = screen(map);
    while (j < i) {
        free(map[j++]);
    }
    free(map);
    return rv;
}
