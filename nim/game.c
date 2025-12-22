/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include <unistd.h>
#include <string.h>
#include "my_printf/print.h"
#include "matchstick.h"

void print_map(tab_t *tab, char *border)
{
    putstr(border);
    write(1, "\n", 1);
    for (int i = 0; i < tab->line; i++)
        my_printf("%i%s%i\n", i+1, tab->map[i], i+1);
    putstr(border);
    write(1, "\n", 1);
}

int play(tab_t *tab, char *name)
{
    int line;
    int match;

    putstr("Line: ");
    line = check_input(tab, 0, tab->line);
    if (line < 0)
        return (line == -1 ? -1 : 3);
    putstr("Matches: ");
    match = check_input(tab, 1, line);
    if (match < 0)
        return (match == -1 ? -1 : 3);
    my_printf("%s removed %i %s from line %i\n", name, match, match == 1 ? "match" : "matches", line);
    return is_map_empty(tab)*2;
}

int game(tab_t *tab)
{
    int i = 0;
    char border[tab->line*2 +2];
    memset(border, '*', tab->line*2 +1);
    border[tab->line*2 +1] = '\0';

    print_map(tab, border);
    while (i <= 0) {
        if (i == 0)
            putstr("\nYour turn:\n");
        i = play(tab, "Player");
        if (i >= 0 && i <= 2)
            print_map(tab, border);
        if (i == 0) {
            putstr("\nAI's turn...\n");
            i = computer(tab);
            print_map(tab, border);
        }
    }
    get_next_line(-1);
    switch (i) {
    case (3) :
        write(1, "\n", 1);
        return 0;
    case (2) :
        putstr("You lost, too bad...\n");
        return 0;
    case (1) :
        putstr("I lost... snif... but I'll get you next time!!\n");
        return 0;
    }
    return 1;
}

int multiplayer(tab_t *tab, char **player_list, int player_nb)
{
    int i = 0;
    int p = 0;
    char border[tab->line*2 +2];
    memset(border, '*', tab->line*2 +1);
    border[tab->line*2 +1] = '\0';

    print_map(tab, border);
    while (i <= 0) {
        if (i == 0)
            my_printf("\n%s's turn:\n", player_list[p]);
        i = play(tab, player_list[p]);
        if (i >= 0 && i <= 2)
            print_map(tab, border);
        if (i == 0)
            p = (p+1) % player_nb;
    }
    get_next_line(-1);
    my_printf("\n%s %s\n", player_list[p], i == 2 ? "lost" : "gave up");
    return p;
}