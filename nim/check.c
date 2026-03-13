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
        fputs(get_msg("error_not_enough_matches"), stderr);
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
        fputs(get_msg("error_line_out_of_range"), stderr);
        return 1;
    }
    if (nb < 0) {
        fputs(get_msg("error_input"), stderr);
        return 1;
    }
    return 0;
}

int match_error(tab_t *tab, int line, int match)
{
    if (match == 0) {
        fputs(get_msg("error_no_remove"), stderr);
        return 1;
    }
    if (match > tab->match) {
        fprintf(stderr, get_msg("error_too_much_remove"), tab->match);
        return 1;
    }
    if (match < 0) {
        fputs(get_msg("error_input"), stderr);
        return 1;
    }
    return (!remove_matches(tab, line-1, match));
}

int check_input(tab_t * tab, int v, int line)
{
    char *str = get_next_line(0);
    if (str == NULL || strcmp(str, get_msg("command_stop")) == 0)
        return -2;

    int var;
    int (*error[2])(tab_t *, int, int) = {line_error, match_error};
    var = getunbr(str);
    free(str);
    if (error[v](tab, line, var))
        return -1;
    return var;
}
