/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef READ_SIZE
#define READ_SIZE 10
#endif

#ifndef MSG
#define MSG

#define LANG_NUM 2
// #define MSG_NUM 29

struct msg {
    char *lang;
    char *msg;
};

struct msg_list {
    char *ind;
    struct msg list[LANG_NUM];
};

const char *get_msg(const char *str);
#endif

#ifndef MATCHSTICK
#define MATCHSTICK

#define ABS(n) (n >= 0 ? n : -(n))

typedef struct tab_stats {
    char **map;
    int *mapnb;
    int line;
    int match;
} tab_t;

typedef struct ai_tab_stats {
    int balance;
    int line;
    int match;
} ai_tab_t;

int game(tab_t *tab);
int multiplayer(tab_t *tab, char **player_list, int player_nb);
int computer(tab_t *tab);

int is_map_empty(tab_t *tab);
int check_input(tab_t * tab, int v, int line);
int remove_matches(tab_t *tab, int line, int match);
char **choose_name(int player);
void take_rand(tab_t *tab);
void free_tab(char **map, int line);

int getunbr(char const *str);
char *get_next_line(int fd);

#endif