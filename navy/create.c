/*
** EPITECH PROJECT, 2019
** create
** File description:
** create
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_printf/print.h"
#include "navy.h"
#include "game.h"

extern game_t game;

int set_boat(int size, int b, int e)
{
    while (b <= e) {
        if (game.player[b/10][b%10] != '.')
            return 0;
        game.player[b/10][b%10] = size+48;
        if (b/10 != e/10)
            b += 10;
        else
            ++b;
    }
    return 1;
}

int check_file(char *str, int *size, int *b, int *e)
{
    int nb[4] = {0, 0, 0, 0};

    *size = str[0]-'0';
    if (my_strlen(str) < 7 || size < 2 || size > 5 || str[1] != ':' || !(nb[size-2]^1))
        return 0;
    if (str[2] < 'A' || str[2] > 'H' || str[3] < '1' || str[3] > '8' || str[4] != ':')
        return 0;
    if (str[5] < 'A' || str[5] > 'H' || str[6] < '1' || str[6] > '8' || (str[7] != '\0' && str[7] != '\n'))
        return 0;

    *b = (str[3]-'1')*10 + str[2]-'A';
    *e = (str[6]-'1')*10 + str[5]-'A';
    if (((*e/10 == *b/10) == (*e%10 == *b%10)) || ((*e/10 - *b/10) | (*e%10 - *b%10)) != *size-1)
        return 0;
    return 1;
}

int fill_map(int fd)
{
    char *str = get_next_line(fd);
    int size = 0;
    int b = 0;
    int e = 0;
    int i = 0;

    while (i < 4 && str) {
        if (!check_file(str, &size, &b, &e))
            return 0;
        if (!set_boat(size, b, e))
            return 0;
        free(str);
        str = NULL;
        str = get_next_line(fd);
        ++i;
    }
    if (i != 4 || str)
        return 0;
    if (str)
        free(str);
    return 1;
}

int create_map(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return 0;
    if ((!fill_map(fd)) | (close(fd) == -1))
        return 0;
    return 1;
}
