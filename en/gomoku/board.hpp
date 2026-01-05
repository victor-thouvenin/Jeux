/*
** EPITECH PROJECT, 2022
** board
** File description:
** header
*/

#pragma once
#define MAX(x,y) (x > y ? x : y)
#define INDMAX(t, x, y) (t[x] > t[y] ? x : y)
typedef short int16;

#include <vector>
#include <string>

class cell {
public:
    enum comb {
        here = -16,
        bad = -15,
        empty = 0,
        simple = 1,
        ssstwins = 2,
        sstwins = 3,
        stwins = 4,
        twins = 5,
        sstriple = 6,
        s_striple = 7,
        striple = 8,
        triple = 9,
        msquadra = 10,
        squadra = 11,
        quadra = 12,
        win = 50,
    };

    enum direction {
        none = 0,
        horizontal = 1,
        vertical = 2,
        dr_diagonal = 3,
        ur_diagonal = -1,
    };

    cell() = default;
    ~cell() = default;
    void operator=(int16 value) { val = value; };
    cell &operator=(const cell&);
    operator int16() { return val; };
    void score(std::vector<comb> &, direction&);
    std::vector<comb> &score(direction&);
    int16 max();
    void set_max(direction&);
    int16 find_best();
    void toward(direction& dr) { dir = dr; };
    direction &toward() { return dir; };
    friend class goban;
private:
    int16 val = 0;
    int16 ind_max[4] = {0, 0, 0, 0};
    std::vector<comb> scr[4] = {{}, {}, {}, {}};
    direction dir = none;
};

class goban {
public:
    goban() = default;
    goban(int16);
    ~goban();
    goban &operator=(const goban&);
    cell &operator[](int16 pos) { return grid[pos]; };
    cell &operator()(int16 x, int16 y) { return grid[x+ y*sz]; };
    int16 find_highest(int16, int16);
    int16 ennemi_highest(int16 x = -1, int16 y = -1);
    int16 ally_highest(int16 x = -1, int16 y = -1);
    int16 size() { return sz; };
    void turn(int16, int16, int16);
    void print();
private:
    cell *grid = NULL;
    int16 sz = 0;
    int16 ennemi_max = -1;
    int16 ally_max = -1;
};

class GameEnd {
public:
    enum gameState {
        error = -1,
        tie = 0,
        p1_won = 1,
        p2_won = 2,
    };
    GameEnd(gameState s) {
        st = s;
        switch (st) {
            case error:
                msg = "an error occurred";
                break;
            case tie:
                msg = "it's a tie";
                break;
            case p1_won:
                msg = "player 1 won. good job!";
                break;
            case p2_won:
                msg = "player 2 won. good job!";
                break;
        }
    };
    GameEnd(gameState s, char const *str) { st = s; msg = str; };
    ~GameEnd() = default;
    gameState const &state() { return st; };
    char const *how() { return msg; };
private:
    gameState st;
    char const *msg;
};

std::vector<cell::comb> convert(int16*);
void find_max(goban &, int16, int16, cell::direction, int16 &, int16, bool update = true);
void check_value(goban &, int16, int16, bool);
void ai_plays(goban &);
