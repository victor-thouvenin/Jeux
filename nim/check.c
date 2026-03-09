/*
** EPITECH PROJECT, 2019
** check
** File description:
** check
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nim.h"

int is_map_empty(tab_t *tab)
{
    int i = 0;

    while (i < tab->line) {
        if (tab->mapnb[i] > 0)
            return 0;
        ++i;
    }
    return 1;
}

int remove_matches(tab_t *tab, int line, int match)
{
    if (tab->mapnb[line] < match) {
        fputs("Error: not enough matches on this line\n", stderr);
        return 0;
    }

    int i = tab->line -line -2 +tab->mapnb[line];
    tab->mapnb[line] -= match;
    while (--match >= 0) {
        tab->map[line][i] = ' ';
        --i;
    }
    return 1;
}

int line_error(tab_t *tab, int line, int nb)
{
    (void)tab;
    if (nb == 0 || nb > line) {
        fputs("Error: this line is out of range\n", stderr);
        return 1;
    }
    if (nb < 0) {
        fputs("Error: invalid input (positive number expected)\n", stderr);
        return 1;
    }
    return 0;
}

int match_error(tab_t *tab, int line, int match)
{
    if (match == 0) {
        fputs("Error: you have to remove at least one match\n", stderr);
        return 1;
    }
    if (match > tab->match) {
        fprintf(stderr, "Error: you cannot remove more than %u matches per turn\n", tab->match);
        return 1;
    }
    if (match < 0) {
        fputs("Error: invalid input (positive number expected)\n", stderr);
        return 1;
    }
    return (!remove_matches(tab, line-1, match));
}

int check_input(tab_t * tab, int v, int line)
{
    char *str = get_next_line(0);
    int var;
    int (*error[2])(tab_t *, int, int) = {line_error, match_error};

    if (str == NULL || strcmp(str, "end") == 0)
        return -2;
    var = getunbr(str);
    free(str);
    if (error[v](tab, line, var))
        return -1;
    return var;
}
