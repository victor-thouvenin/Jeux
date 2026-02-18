/*
** EPITECH PROJECT, 2019
** game_sig
** File description:
** game signal
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf/print.h"
#include "navy.h"

int send_signal(game_t *game, int act, int pos)
{
    int sig[2] = {U2, U1};
    int i = 7;

    while (i >= 2) {
        kill(game->eid, sig[(pos >> (i - 2)) % 2]);
        usleep(10000);
        --i;
    }
    while (i >= 0) {
        kill(game->eid, sig[(act >> i) % 2]);
        usleep(10000);
        --i;
    }
    return 0;
}

int check_pos(game_t *game)
{
    int sig = game->sig >> 2;
    int x = sig&7;
    int y = sig >> 3;

    my_printf("%c%c: ", x + 'A', y + '1');
    if (game->player[y][x] >= '2' && game->player[y][x] <= '5') {
        game->player[y][x] = 'x';
        my_putstr("touché\n\n");
        send_signal(game, 3, sig);
    } else {
        if (game->player[y][x] != 'x')
            game->player[y][x] = 'o';
        my_putstr("manqué\n\n");
        send_signal(game, 2, sig);
    }
    return 0;
}

void check_hit(game_t *game)
{
    int sig = game->sig >> 2;

    if (game->sig % 4 == 2) {
        if (game->enemy[sig >> 3][sig&7] != 'x')
            game->enemy[sig >> 3][sig&7] = 'o';
        my_putstr("manqué\n\n");
    }
    else if (game->sig % 4 == 3) {
        game->enemy[sig >> 3][sig&7] = 'x';
        my_putstr("touché\n\n");
    }
}

int check_signal(game_t *game)
{
    int i = 0;
    int t = 0;

    if (game->end)
        return 1;
    while (i < 7) {
        t = usleep(1500000);
        if (!t) {
            puterror("erreur de connexion\n");
            return 0;
        }
        ++i;
    }
    return 1;
}

int receive_signal(game_t *game)
{
    if (!check_signal(game)) {
        kill(game->eid, U2);
        return 0;
    }
    switch (game->sig&3) {
    case (0):
        game->end = -1;
        if (game->sig)
            game->end = 2;
        break;
    case (1):
        check_pos(game);
        break;
    default:
        check_hit(game);
    }
    return 1;
}
