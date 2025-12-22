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

    my_putstr("my positions:\n |A B C D E F G H\n-+---------------");
    while (i < 8) {
        my_printf("\n%i|%c", i + 1, game->player[i][j]);
        while (++j < 8)
            my_printf(" %c", game->player[i][j]);
        j = 0;
        ++i;
    }
    my_putstr("\n\nenemy's positions:\n |A B C D E F G H\n-+---------------");
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

    my_putstr("attack: ");
    str = get_next_line(0);
    if (str && str[0] >= 'A' && str[0] <= 'H' && str[1] >= '1' && str[1] <= '8' && !str[2]) {
        my_printf("%s: ", str);
        pos = (str[1]-'1')*8 + *str-'A';
        free(str);
    } else if (str) {
        free(str);
        my_putstr("wrong position\n");
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

int check_ans(game_t *game, int play)
{
    if (!usleep(1500000))
        return puterror("connection error\n");
    if (!receive_signal(game))
        return 1;
    if (!play)
        print_map(game);
    my_putstr("waiting for enemy's attack...\n");
    game->sig = 0;
    pause();
    if (!receive_signal(game))
        return 1;
    check_end(game);
    return 0;
}

int game_loop(game_t *game, int play)
{
    int sig;
    int error = 0;

    while (!game->end && !error) {
        game->sig = 0;
        sig = take_turn(game);
        if (sig >= 0) {
            send_signal(game, 1, sig);
            error = check_ans(game, play);
        }
        if (sig >= 0 && (play || game->end > 0))
            print_map(game);
    }
    if (game->end == 1)
        my_putstr("Enemy won\n");
    if (game->end == 2)
        my_putstr("I won\n");
    get_next_line(-1);
    return (error ? error : game->end % 2);
}

int start(struct sigaction *sa, game_t *game, int play)
{
    int end;

    sa->sa_sigaction = handle_sig;
    if (sigaction(SIGINT, sa, NULL) == -1 ||
    sigaction(U1, sa, NULL) == -1 || sigaction(U2, sa, NULL) == -1)
        return puterror("connection error\n");
    print_map(game);
    if (!play) {
        my_putstr("waiting for enemy's attack...\n");
        pause();
        if (!receive_signal(game))
            return 1;
    }
    end = game_loop(game, play);
    return (end >= 0 ? end : 0);
}
