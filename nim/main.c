/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nim.h"

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

    if (tab->map == NULL)
        return 0;
    tab->mapnb = create_int_map(line);
    if (tab->mapnb == NULL) {
        free_tab(tab->map, line);
        return 0;
    }

    tab->line = line;
    tab->match = match&255;
    return 1;
}

int start (int line, int match, int player_nb)
{
    tab_t tab;
    if (!set_tab(&tab, line, match)) {
        fputs(get_msg("error_memory"), stderr);
        return 1;
    }

    char **player_list = NULL;
    if (player_nb > 1) {
        player_list = choose_name(player_nb);
        if (player_list == NULL) {
            fputs(get_msg("error_general"), stderr);
            return 1;
        }
    }

    int p = game(&tab, player_list, player_nb);
    while (player_nb > 1) {
        free (player_list[p]);
        while (player_list[p]) {
            player_list[p] = player_list[p+1];
            ++p;
        }
        if (--player_nb > 1) {
            printf(get_msg("multi-players_remaining"), player_nb);
            reset_tab(&tab);
            p = game(&tab, player_list, player_nb);
        } else {
            printf(get_msg("multi-players_win"), player_list[0]);
            get_next_line(-1);
        }
    }
    if (player_list != NULL)
        free_tab(player_list, player_nb);
    free_tab(tab.map, tab.line);
    free(tab.mapnb);
    return 0;
}

int check_opt(int ac, char **av, int *ind)
{
    int i = 0;
    while (++i < ac) {
        if (strncmp(av[i], "-lang=", 6) == 0) {
            if (is_lang(av[i]+6))
                change_lang(av[i]+6, 0);
            else {
                fprintf(stderr, get_msg("error_lang"), av[i]+6);
                print_lang();
                return 0;
            }
        } else if (*av[i] == '-' && av[i][1] != '\0') {
            fprintf(stderr, get_msg("error_option"), av[i]);
            return 0;
        } else if (++*ind != i) {
            strcpy(av[*ind], av[i]);
        }
    }
    if (*ind < 1 || *ind > 3) {
        fprintf(stderr, get_msg("error_parameter"), *ind);
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int pnum = 0;
    if (!check_opt(ac, av, &pnum)) {
        return 1;
    }

    int line = getunbr(av[1]);
    if (line < 2 || line > 99) {
        fputs(get_msg("error_line"), stderr);
        return 1;
    }
    if (pnum == 1) {
        return start(line, -1, 1);
    }

    int match;
    if (*av[2] == '-' && av[2][1] == '\0')
        match = -1;
    else {
        match = getunbr(av[2]);
        if (match < 2) {
            fputs(get_msg("error_match"), stderr);
            return 1;
        }
    }
    if (pnum == 2) {
        return start(line, match, 1);
    }

    int player_nb = getunbr(av[3]);
    if (player_nb < 1 || player_nb > 9) {
        fputs(get_msg("error_multi"), stderr);
        return 1;
    }
    return start(line, match, player_nb);
}
