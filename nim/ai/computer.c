/*
** EPITECH PROJECT, 2019
** computer
** File description:
** computer
*/

#include <stdio.h>
#include "../nim.h"

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

    while ((tab->mapnb[line]&n) == 0) {
        ++line;
    }

    int nb = tab->mapnb[line]&unbalance;
    int nb2 = nb^unbalance;
    if (nb-nb2 > tab->match) {
        nb = 0;
        nb2 = 0;
        for (int i = 1; i <= tab->mapnb[line] ; i <<= 1) {
            if ((i&unbalance) != 0 && i-nb2 <= tab->match)
                nb = i;
            else if ((i&unbalance) == 0 && i-nb <= tab->match)
                nb2 = i;
            else
                break;
        }
    }
    int match = ABS(nb-nb2);

    remove_matches(tab, line, match);
    printf(get_msg("AI_played"), match, line+1);
}

int ai_play(tab_t *tab, int line, int match)
{
    remove_matches(tab, line, match);
    printf(get_msg("AI_played"), match, line+1);
    return 1;
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

    if (!sl) {
        while (tab->mapnb[--line] == 0){}
        return ai_play(tab, line, 1);
    }

    int match = tab->mapnb[line] -(nb&1);
    if (match <= tab->match) {
        return ai_play(tab, line, match);
    }

    match = tab->mapnb[line]%(tab->match+1);
    if (match == 0 && (nb&1) == 1)
        return ai_play(tab, line, tab->match);
    if (match == 1 && (nb&1) == 0)
        return ai_play(tab, line, 1);
    if (nb > 1 && (match == 0 || match == 1)) {
        line = 0;
        while (tab->mapnb[line++] != 1){}
        return ai_play(tab, line, 1);
    }
    if (match == 1) {
        return ai_play(tab, line, 1);
    }
    return ai_play(tab, line, match-(nb&1));
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
