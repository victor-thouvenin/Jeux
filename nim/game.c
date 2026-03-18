/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "nim.h"

void print_map(tab_t *tab)
{
    puts(tab->border);
    for (int i = 0; i < tab->line; i++)
        printf("%2i%s%i\n", i+1, tab->map[i], tab->mapnb[i]);
    puts(tab->border);
}

int play(tab_t *tab, const char *name, int multi)
{
    int line;
    int match;

    fputs(get_msg("ask_line"), stdout);
    fflush(stdout);
    line = check_input(tab, 0, tab->line);
    if (line <= 0)
        return (line == -2 ? 3 : -1);
    fputs(get_msg("ask_match"), stdout);
    fflush(stdout);
    match = check_input(tab, 1, line);
    if (match <= 0)
        return (match == -2 ? 3 : -1);
    print_map(tab);
    if (multi)
        printf(get_msg("multi-player_played"), name, match, line);
    else
        printf(get_msg("player_played"), match, line);
    return is_map_empty(tab)*2;
}

int singleplayer(tab_t *tab)
{
    int i = 0;
    print_map(tab);
    while (i <= 0) {
        if (i == 0)
            puts(get_msg("player_turn"));
        i = play(tab, "", 0);
        if (i == 0) {
            puts(get_msg("AI_turn"));
            i = computer(tab);
        }
    }
    get_next_line(-1);
    switch (i) {
    case (3) :
        write(1, "\n", 1);
        return 0;
    case (2) :
        puts(get_msg("player_lost"));
        return 0;
    case (1) :
        puts(get_msg("AI_lost"));
        return 0;
    }
    return 1;
}

int multiplayer(tab_t *tab, char **player_list, int player_nb)
{
    int i = 0;
    int p = 0;

    print_map(tab);
    while (i <= 0) {
        if (i == 0)
            printf(get_msg("multi-player_turn"), player_list[p]);
        i = play(tab, player_list[p], 1);
        if (i == 0)
            p = (p+1) % player_nb;
    }
    printf(get_msg(i == 2 ? "multi-player_lost" : "multi-player_gave_up"), player_list[p]);
    return p;
}

int game(tab_t *tab, char **player_list, int player_nb)
{
    char border[tab->line*2 +3];
    border[0] = ' ';
    memset(border+1, '*', tab->line*2 +1);
    border[tab->line*2 +2] = '\0';
    tab->border = border;

    if (player_nb <= 1)
        return singleplayer(tab);
    return multiplayer(tab, player_list, player_nb);
}