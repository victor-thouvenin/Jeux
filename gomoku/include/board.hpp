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
    void operator=(const int16 &value) { val = value; };
    cell &operator=(const cell &);
    operator int16() { return val; };
    void score(const std::vector<comb> &, const direction &);
    std::vector<comb> &score(const direction &);
    int16 max();
    void set_max(const direction &);
    int16 find_best();
    void toward(const direction &dr) { dir = dr; };
    const direction &toward() { return dir; };
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
    goban(const int16);
    ~goban();
    cell &operator[](const int16 &pos) { return grid[pos]; };
    cell &operator()(const int16 &x, const int16 &y) { return grid[x+ y*sz]; };
    int16 find_highest(const int16 &, const int16 &high = 0);
    int16 ennemi_highest(const int16 &x = -1, const int16 &y = -1);
    int16 ally_highest(const int16 &x = -1, const int16 &y = -1);
    int16 size() { return sz; };
    void turn(const int16 &, const int16 &, const int16 &);
    void print();
private:
    cell *grid = NULL;
    int16 sz = 0;
    int16 ennemi_max = -1;
    int16 ally_max = -1;
};

std::vector<cell::comb> convert(const int16 *);
void find_max(goban &, const int16 &, const int16 &, const int16 &, const cell::direction&, int16 &, const int16 &, const bool &update = true);
void check_value(goban &, const int16 &, const int16 &, const bool &);
void ai_plays(goban &);
