/*
** EPITECH PROJECT, 2018
** screen
** File description:
** screen
*/

#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include "sokoban.h"

ntt_t *get_ntt(ntt_t *nttl, point_t pos, char ntt)
{
    while (nttl != NULL && (nttl->ntt != ntt || nttl->pos.x != pos.x || nttl->pos.y != pos.y)) {
        nttl = nttl->next;
    }
    return nttl;
}

void reset(char **map, ntt_t *nttl)
{
    int i = 0;
    int j = 0;

    while (map[i]) {
        if (map[i][j] == 'P' || map[i][j] == 'X')
            map[i][j] = ' ';
        if (map[i][j] == '\0') {
            ++i;
            j = -1;
        }
        ++j;
    }
    while (nttl) {
        nttl->pos.x = nttl->basic_pos.x;
        nttl->pos.y = nttl->basic_pos.y;
        map[nttl->pos.x][nttl->pos.y] = nttl->ntt;
        nttl = nttl->next;
    }
}

void check_move(char **map, ntt_t *nttl, ntt_t *pl, point_t m)
{
    point_t pos = {pl->pos.x + m.x, pl->pos.y + m.y};
    point_t pos2 = {pos.x + m.x, pos.y + m.y};

    if (pos.x < 0 || map[pos.x] == NULL || pos.y < 0 || pos.y >= (int)strlen(map[pos.x]) || map[pos.x][pos.y] == '#' ||
        (map[pos.x][pos.y] == 'X' &&
         (pos2.x < 0 || map[pos2.x] == NULL || pos2.y < 0 || pos2.y >= (int)strlen(map[pos2.x]) || map[pos2.x][pos2.y] == '#' || map[pos2.x][pos2.y] == 'X')))
        return;

    ntt_t *cur = NULL;
    if (map[pos.x][pos.y] == 'X') {
        cur = get_ntt(nttl, pos, 'X');
        cur->pos.x = pos2.x;
        cur->pos.y = pos2.y;
        map[pos2.x][pos2.y] = 'X';
    }
    map[pl->pos.x][pl->pos.y] = ' ';
    pos2 = pl->pos;
    pl->pos = pos;
    map[pl->pos.x][pl->pos.y] = 'P';

    if (get_ntt(nttl, pos2, 'O') != NULL)
        map[pos2.x][pos2.y] = 'O';
}

void move_p(char **map, ntt_t *nttl, int key)
{
    point_t m[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    ntt_t *pl = nttl;

    while (pl->ntt != 'P')
        pl = pl->next;
    check_move(map, nttl, pl, m[key - KEY_DOWN]);
}

int check_cell(char c, int i, int j, ntt_t **nttl)
{
    ntt_t *prev;

    if (c == 'P' || c == 'O' || c == 'X') {
        prev = malloc(sizeof(ntt_t));
        if (prev == NULL)
            return 0;
        prev->ntt = c;
        prev->pos.x = i;
        prev->pos.y = j;
        prev->basic_pos.x = i;
        prev->basic_pos.y = j;
        prev->next = *nttl;
        *nttl = prev;
    }
    return 1;
}

void free_ntt_list(ntt_t *nttl)
{
    ntt_t *next = nttl;

    while (nttl) {
        next = nttl->next;
        free(nttl);
        nttl = next;
    }
}

ntt_t *create_ntt_list(char **map)
{
    ntt_t *nttl = NULL;
    int i = 0;
    int j;

    while (map[i]) {
        j = 0;
        while (map[i][j]) {
            if (!check_cell(map[i][j], i, j, &nttl)) {
                free_ntt_list(nttl);
                return NULL;
            }
            ++j;
        }
        ++i;
    }
    return nttl;
}

int screen(char **map)
{
    int b = 0;
    int key = 0;
    ntt_t *nttl = create_ntt_list(map);

    if (nttl == NULL)
        return 1;
    initscr();
    keypad(stdscr, true);
    while (1) {
        for (int i = 0; map[i] != NULL; i++)
            printw("%s\n", map[i]);
        if (b == 1)
            printw("win\n");
        if (b == -1)
            printw("loose\n");
        key = getch();
        clear();
        if (key == ' ')
            reset(map, nttl);
        else if (b != 0 || key == 'q' || key == KEY_END)
            break;
        else if (key >= KEY_DOWN && key <= KEY_RIGHT)
            move_p(map, nttl, key);
        b = check_end(map, nttl);
        refresh();
    }
    endwin();
    free_ntt_list(nttl);
    return 0;
}
