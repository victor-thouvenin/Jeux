/*
** EPITECH PROJECT, 2019
** computer
** File description:
** computer
*/

#include "../my_printf/print.h"
#include "../matchstick.h"

int check_balance(tab_t *tab, int *ub)
{
    int n = 0;
    int size = tab->line*2 -1;

    for (int nb = 1; nb < size; nb <<= 1) {
        for (int i = 0; i < tab->line; i++)
            *ub ^= tab->mapnb[i]& nb;
        if ((*ub& nb) != 0)
            n = nb;
    }
    return n;
}

void choose_line(tab_t *tab, int unbalance, int n)
{
    int line = 0;

    while ((tab->mapnb[line]&n) == 0)
        ++line;

    int nb = tab->mapnb[line]&unbalance;
    int nb2 = nb^unbalance;
    if (nb-nb2 > tab->match) {
        nb = 0;
        nb2 = 0;
        for (int i = 1; i-nb2 <= tab->match || i-nb <= tab->match ; i <<= 1) {
            if ((i&unbalance) != 0)
                nb = i;
            else
                nb2 = i;
            if ((nb&nb2) != 0)
                break;
        }
    }
    int match = ABS(nb-nb2);

    remove_matches(tab, line, match);
    my_printf("AI removed %d %s from line %d\n", match, match == 1 ? "match" : "matches", line+1);
}

int find_single_line(tab_t *tab)
{
    int line = 0;
    int nb = 0;
    int sl = 0;
    for (int i = 0; i < tab->line; i++) {
        if (tab->mapnb[i] > 0)
            ++nb;
        if (tab->mapnb[i] > 1) {
            if (sl)
                return 0;
            sl = 1;
        }
        if (!sl)
            line++;
    }

    int match;
    if (sl == 0)
        match = 1;
    else {
        match = tab->mapnb[line] -(nb&1);
        if (match > tab->match)
            match = tab->mapnb[line] -((tab->match+1)*(tab->mapnb[line]/(tab->match+1)) +2 -(nb&1));
        if (match == 0)
            match = tab->match/2;
    }
    remove_matches(tab, line, match);
    my_printf("AI removed %d %s from line %d\n", match, match == 1 ? "match" : "matches", line+1);
    return 1;
}

int computer(tab_t *tab)
{
    int unbalance = 0;
    int nb = check_balance(tab, &unbalance);
    if (unbalance == 0)
        take_rand(tab);
    else if (!find_single_line(tab))
            choose_line(tab, unbalance, nb);
    return is_map_empty(tab);
}
