/*
** EPITECH PROJECT, 2019
** take_rand
** File description:
** take a rand
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../nim.h"

void take_rand(tab_t *tab)
{
    srand(time(NULL));
    int line = rand()%tab->line;
    while (tab->mapnb[line] < 1)
        line = rand()%tab->line;
    int match = rand()%tab->mapnb[line] %tab->match +1;
    remove_matches(tab, line, match);
    printf(get_msg("AI_played"), match, line+1);
}
