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

void print_map(tab_t *tab, char *border)
{
    puts(border);
    for (int i = 0; i < tab->line; i++)
        printf("%i%s%i\n", i+1, tab->map[i], i+1);
    puts(border);
}

int play(tab_t *tab, char *name)
{
    int line;
    int match;

    fputs("Line: ", stdout);
    line = check_input(tab, 0, tab->line);
    if (line < 0)
        return (line == -1 ? -1 : 3);
    fputs("Matches: ", stdout);
    match = check_input(tab, 1, line);
    if (match < 0)
        return (match == -1 ? -1 : 3);
    printf("%s removed %i %s from line %i\n", name, match, match == 1 ? "match" : "matches", line);
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
            puts("\nYour turn:");
        i = play(tab, "Player");
        if (i >= 0 && i <= 2)
            print_map(tab, border);
        if (i == 0) {
            puts("\nAI's turn...");
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
        puts("You lost, too bad...");
        return 0;
    case (1) :
        puts("I lost... snif... but I'll get you next time!!");
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
            printf("\n%s's turn:\n", player_list[p]);
        i = play(tab, player_list[p]);
        if (i >= 0 && i <= 2)
            print_map(tab, border);
        if (i == 0)
            p = (p+1) % player_nb;
    }
    get_next_line(-1);
    printf((i == 2 ? "\n%s lost\n" : "\n%s gave up\n"), player_list[p]);
    return p;
}