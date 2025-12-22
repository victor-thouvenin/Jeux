/*
** EPITECH PROJECT, 2018
** check
** File description:
** check
*/

#include <string.h>
#include <stdlib.h>
#include "sokoban.h"

int check_loose(char ** map, ntt_t *nttl)
{
    while (nttl) {
        if (nttl->ntt == 'X' &&
            ((nttl->pos.x -1 >= 0 && map[nttl->pos.x +1] != NULL &&
              nttl->pos.y < (int)strlen(map[nttl->pos.x -1]) && map[nttl->pos.x -1][nttl->pos.y] != '#' && map[nttl->pos.x -1][nttl->pos.y] != 'X' &&
              nttl->pos.y < (int)strlen(map[nttl->pos.x +1]) && map[nttl->pos.x +1][nttl->pos.y] != '#' && map[nttl->pos.x +1][nttl->pos.y] != 'X') ||
             (nttl->pos.y -1 >= 0 && map[nttl->pos.x][nttl->pos.y +1] != '\0' &&
              map[nttl->pos.x][nttl->pos.y -1] != '#' && map[nttl->pos.x][nttl->pos.y -1] != 'X' &&
              map[nttl->pos.x][nttl->pos.y +1] != '#' && map[nttl->pos.x][nttl->pos.y +1] != 'X'))) {
            return 0;
        }
        nttl = nttl->next;
    }
    return -1;
}

int check_end(char ** map, ntt_t *nttl)
{
    ntt_t *start = nttl;
    while (nttl) {
        if (nttl->ntt == 'O' && map[nttl->pos.x][nttl->pos.y] != 'X')
            return check_loose(map, start);
        nttl = nttl->next;
    }
    return 1;
}

int check_str(char *str)
{
    int i = 0;
    int j = 0;
    int p = 0;
    int o = 0;

    while (str[j]) {
        if (j != 0 && (str[j-1] != '\n' && str[j] == '\n') && (str[j] == '\n' || str[j+1] == '\0'))
            ++i;
        else if (str[j] != 'P' && str[j] != 'O' && str[j] != 'X' && str[j] != ' ' && str[j] != '#' && str[j] != '\n')
            return -1;
        switch (str[j])
        {
        case 'P':
            ++p;
            break;
        case 'O':
            ++o;
            break;
        case 'X':
            --o;
            break;
        }
        if (p > 2)
            return -1;
        ++j;
    }
    if (p == 0 || o > 0)
        return -1;
    return i;
}
