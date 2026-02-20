/*
** EPITECH PROJECT, 2019
** start
** File description:
** start
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "my_printf/print.h"
#include "navy.h"

void print_map(game_t *game)
{
    int i = 0;
    int j = 0;

    my_putstr("mes bateaux :\n |A B C D E F G H\n-+---------------");
    while (i < 8) {
        my_printf("\n%i|%c", i + 1, game->player[i][j]);
        while (++j < 8)
            my_printf(" %c", game->player[i][j]);
        j = 0;
        ++i;
    }
    my_putstr("\n\nbateaux enemis :\n |A B C D E F G H\n-+---------------");
    for (i = 0; i < 8; i++) {
        my_printf("\n%i|%c", i + 1, game->enemy[i][j]);
        while (++j < 8)
            my_printf(" %c", game->enemy[i][j]);
        j = 0;
    }
    my_putstr("\n\n");
}

int take_turn(game_t *game)
{
    char *str = NULL;
    int pos = 0;

    my_putstr("attaque : ");
    str = get_next_line(0);
    if (str && str[0] >= 'A' && str[0] <= 'H' && str[1] >= '1' && str[1] <= '8' && str[2] == '\0') {
        my_printf("%s : ", str);
        pos = ((str[1]-'1')<<3) + str[0]-'A';
        free(str);
    } else if (str) {
        free(str);
        my_putstr("position érronée\n");
        return -1;
    } else {
        send_signal(game, 0, 0);
        game->end = -1;
        return -1;
    }
    return pos;
}

void check_end(game_t *game)
{
    int i = 0;
    int j = 0;

    while (i < 8) {
        if (game->player[i][j] >= '2' && game->player[i][j] <= '5')
            return;
        if (++j == 8) {
            ++i;
            j = 0;
        }
    }
    game->end = 1;
    send_signal(game, 0, 1);
}

int check_ans(game_t *game)
{
    if (!receive_signal(game)) {
        game->end = -1;
        return 0;
    }
    game->sig = 0;
    print_map(game);
    my_putstr("en attente de l'attaque de l'ennemie ...\n");
    pause();
    if (game->end == -2 || !receive_signal(game))
        return 0;
    check_end(game);
    return 1;
}

int game_loop(game_t *game)
{
    int sig;

    print_map(game);
    while (game->end == 0) {
        game->sig = 0;
        sig = take_turn(game);
        if (sig >= 0) {
            send_signal(game, 1, sig);
            if (!check_ans(game))
                break;
            print_map(game);
        }
    }
    if (game->end == 1)
        my_putstr("Défaite\n");
    if (game->end == 2)
        my_putstr("Victoire\n");
    if (game->end == -1)
        my_putstr("erreur de connexion\n");
    get_next_line(-1);
    return (game->end < 0);
}

int start(struct sigaction *sa, game_t *game, int play)
{
    sa->sa_sigaction = handle_sig;
    if (sigaction(SIGINT, sa, NULL) == -1 ||
    sigaction(U1, sa, NULL) == -1 || sigaction(U2, sa, NULL) == -1)
        return puterror("erreur de connexion\n");
    if (play == 0) {
        print_map(game);
        my_putstr("en attente de l'attaque de l'ennemie ...\n");
        pause();
        if (game->end == -2 || !receive_signal(game))
            return 1;
    }
    return (game_loop(game));
}
