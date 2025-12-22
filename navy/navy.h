/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef NAVY
#define NAVY
#define U1 SIGUSR1
#define U2 SIGUSR2

#include <signal.h>

typedef struct game_stat {
    char player[8][8];
    char enemy[8][8];
    int eid;
    int end;
    unsigned char sig;
} game_t;

int receive_signal(game_t *);
int send_signal(game_t *, int, int);
void handle_sig(int, siginfo_t *, void *);

int create_map(char *);
int check_end(game_t *);

char *get_next_line(int);
int puterror(char const *);
int my_getunbr(char const *);
int my_strcmp(char const *, char const *);

int start(struct sigaction *, game_t *, int);
void setaction(struct sigaction *);

#endif

#ifndef READ_SIZE
#define READ_SIZE 8
#endif
