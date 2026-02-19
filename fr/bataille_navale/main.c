/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <sys/types.h>
#include <unistd.h>
#include "my_printf/print.h"
#include "navy.h"

extern game_t game;

char *connect_err_msg = "erreur de connexion\n";

int log_p1(char *file)
{
    struct sigaction sa;

    setaction(&sa);
    if (!create_map(file))
        return 1;
    my_printf("PID: %i\n", getpid());
    if (sigaction(U2, &sa, NULL) == -1)
        return puterror(connect_err_msg);
    my_putstr("En attente de l'ennemi ...\n\n");
    pause();
    if (game.eid) {
        kill(game.eid, U1);
        my_putstr("enemi connecté\n\n");
        return start(&sa, &game, 1);
    }
    return 0;
}

int log_p2(int pid, char *file)
{
    struct sigaction sa;
    int t;

    setaction(&sa);
    if (!create_map(file))
        return 1;
    my_printf("PID: %i\n", getpid());
    if (sigaction(U1, &sa, NULL) == -1)
        return puterror(connect_err_msg);
    kill(pid, U2);
    t = sleep(2);
    if (t == 0)
        return puterror(connect_err_msg);
    if (game.eid) {
        my_putstr("connecté\n\n");
        return start(&sa, &game, 0);
    }
    return 0;
}

int main(int ac, char **av)
{
    int pid;

    if (ac < 2 || ac > 3)
        return 1;
    if (ac == 2)
        return log_p1(av[1]);
    pid = my_getunbr(av[1]);
    if (pid <= 0)
        return 1;
    return log_p2(pid, av[2]);
}
