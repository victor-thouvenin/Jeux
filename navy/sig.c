/*
** EPITECH PROJECT, 2019
** sig
** File description:
** sig
*/

#include <signal.h>
#include "navy.h"

extern game_t game;

void give_up(void)
{
    if (game.eid)
        send_signal(&game, 0, 0);
    game.end = -1;
}

void handle_sig(int sig, siginfo_t *info, void *ptr)
{
    (void)ptr;
    (void)info;
    if (sig == SIGINT)
        return give_up();
    if (sig == U1 || sig == U2) {
        game.sig *= 2;
        if (sig == U1)
            ++game.sig;
    }
}

void act(int sig, siginfo_t *info, void *ptr)
{
    (void)ptr;
    if (sig == SIGINT) {
        give_up();
        return;
    }
    if (info && !game.eid)
        game.eid = info->si_pid;
}

void setaction(struct sigaction *sa)
{
    sa->sa_flags = SA_SIGINFO;
    sa->sa_sigaction = act;
}
