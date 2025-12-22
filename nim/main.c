/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_printf/print.h"
#include "matchstick.h"

void free_tab(char **tab, int line)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (i < line)
        free(tab[i++]);
    free(tab);
}

int *create_int_map(int line)
{
    int *map = malloc(sizeof(int)*line);

    if (map == NULL)
        return NULL;
    for (int i = 0; i < line; i++)
        map[i] = 2 * i + 1;
    return map;
}

void reset_tab(tab_t *tab)
{
	for (int i = 0; i < tab->line; i++) {
        tab->mapnb[i] = 2*i +1;
        for (int j = 0; j < tab->line*2 -1; j++)
            tab->map[i][j] = j >= tab->line -i -1 && j < tab->line +i ? '|' : ' ';
	}
}

char **create_map(int line)
{
    char **map = malloc(sizeof(char*)*line);

    if (map == NULL)
        return NULL;

    int i = 0;
    while (i < line) {
        map[i] = malloc(line*2);
        if (map[i] == NULL) {
            free_tab(map, i+1);
            return NULL;
        }
        for (int j = 0; j < line*2-1; j++)
            map[i][j] = j >= line-i -1 && j < line+i ? '|' : ' ';
        map[i++][line*2 -1] = '\0';
    }
    return map;
}

int set_tab(tab_t *tab, int line, int match)
{
    tab->map = create_map(line);

    if (tab->map != NULL)
        tab->mapnb = create_int_map(line);
    if (tab->map == NULL || tab->mapnb == NULL) {
        puterror("an error occured\n");
        free_tab(tab->map, line);
        free(tab->mapnb);
        return 0;
    }

    tab->line = line;
    tab->match = match&255;
    return 1;
}

int start (int line, int match, int player_nb)
{
    tab_t tab;
    if (!set_tab(&tab, line, match))
        return 1;

    if (player_nb == 1)
        game(&tab);
    else {
        char **player_list = choose_name(player_nb);
        if (player_list == NULL) {
            puterror("an error occured\n");
            return 1;
        }
        while (player_nb > 1) {
            int p = multiplayer(&tab, player_list, player_nb);
            free (player_list[p]);
            while (player_list[p]) {
                player_list[p] = player_list[p+1];
                ++p;
            }
            if (--player_nb > 1) {
                my_printf("\n%i players remaining\n\n", player_nb);
                reset_tab(&tab);
            } else
                my_printf("\n%s win\n", player_list[0]);
        }
        free_tab(player_list, player_nb);
    }
    free_tab(tab.map, tab.line);
    free(tab.mapnb);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 4) {
        fprintf(stderr, "ERROR: between 1 and 3 arguments needed got %i\n", ac-1);
        return 1;
    }

    int line = getunbr(av[1]);
    if (line < 2 || line > 99) {
        puterror("ERROR: number of line must be a number between 2 and 99\n");
        return 1;
    }

    int match = ac > 2 ? getunbr(av[2]) : -1;
    if (ac > 2 && match < 2) {
        puterror("ERROR: maximum match removal number must be a number greater than 1\n");
        return 1;
    }

    int player_nb = ac == 4 ? getunbr(av[3]) : 1;
    if (ac == 4 && (player_nb < 1 || player_nb > 9)) {
        puterror("ERROR: number of player must be a number between 1 and 9\n");
        return 1;
    }
    return start(line, match, player_nb);
}
