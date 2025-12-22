/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

typedef struct point {
    int x;
    int y;
} point_t;

typedef struct entity_list {
    char ntt;
    point_t basic_pos;
    point_t pos;
    struct entity_list *next;
} ntt_t;

int check_end(char ** map, ntt_t *nttl);
int screen(char **map);
int check_str(char *str);

#endif
