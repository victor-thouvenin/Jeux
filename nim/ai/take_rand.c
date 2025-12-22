/*
** EPITECH PROJECT, 2019
** take_rand
** File description:
** take a rand
*/

#include <stdlib.h>
#include <time.h>
#include "../my_printf/print.h"
#include "../matchstick.h"

void take_rand(tab_t *tab)
{
    srand(time(NULL));
    int line = rand()%tab->line;
    while (tab->mapnb[line] < 1)
        line = rand()%tab->line;
    int match = rand()%tab->mapnb[line] %tab->match +1;
    remove_matches(tab, line, match);
    my_printf("AI removed %d %s from line %d\n", match, match == 1 ? "match" : "matches", line+1);
}
