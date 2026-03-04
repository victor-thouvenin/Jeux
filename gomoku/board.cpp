/*
** EPITECH PROJECT, 2022
** board
** File description:
** board
*/

#include <iostream>
#include "include/board.hpp"
#include "include/game_end.hpp"

cell &cell::operator=(const cell &cell)
{
    val = cell.val;
    ind_max[0] = cell.ind_max[0];
    ind_max[1] = cell.ind_max[1];
    ind_max[2] = cell.ind_max[2];
    ind_max[3] = cell.ind_max[3];
    scr[0] = cell.scr[0];
    scr[1] = cell.scr[1];
    scr[2] = cell.scr[2];
    scr[3] = cell.scr[3];
    dir = cell.dir;
    return *this;
}

void cell::score(const std::vector<cell::comb> &comb, const cell::direction &dr)
{
    if (dr == none)
        return;
    int16 ind = dr > 0 ? dr-1 : 3;
    scr[ind] = comb;
    set_max(dr);
}

std::vector<cell::comb> &cell::score(const cell::direction &dr)
{
    if (dr == none)
        throw "no direction";
    int16 ind = dr > 0 ? dr-1 : 3;
    return scr[ind];
}

int16 cell::max()
{
    if (dir == none)
        return 0;
    int16 ind = dir > 0 ? dir-1 : 3;
    return ind_max[ind];
}

void cell::set_max(const cell::direction &dr)
{
    if (dr == none)
        return;
    int16 ind = dr == -1 ? 3 : dr-1;
    std::vector<cell::comb> &max = scr[ind];
    ind_max[ind] = INDMAX(max, 4, INDMAX(max, INDMAX(max, 3, 2), INDMAX(max, 1, 0)));
}

int16 cell::find_best()
{
    int16 best = scr[0][ind_max[0]] >= scr[1][ind_max[1]] ? 0 : 1;
    if (scr[2][ind_max[2]] > scr[best][ind_max[best]])
        best = 2;
    if (scr[3][ind_max[3]] > scr[best][ind_max[best]])
        best = 3;
    dir = static_cast<cell::direction>(best == 3 ? -1 : best+1);
    return scr[best][ind_max[best]];
}

goban::goban(const int16 size)
{
    try {
        grid = new cell[size*size];
        sz = size;
    } catch (...) {
        throw;
    }
}

goban::~goban()
{
    if (grid != NULL)
        delete[] grid;
}

int16 goban::find_highest(const int16 &sign, const int16 &high)
{
    int16 v;
    int16 highest = high;
    int16 max = grid[highest]*sign;
    for (int i = 0; i < sz*sz; i++) {
        v = grid[i]*sign;
        if (v != -cell::bad && v > 0 && v > max) {
            highest = i;
            max = v;
        }
    }
    return highest;
}

int16 goban::ennemi_highest(const int16 &x, const int16 &y)
{
    if (x == -1 || y == -1)
        return ennemi_max;

    int16 pos = x + sz*y;
    if (grid[pos] != cell::bad && grid[pos] < 0 && (ennemi_max == -1 || grid[pos] < grid[ennemi_max]))
        ennemi_max = pos;
    return ennemi_max;
}

int16 goban::ally_highest(const int16 &x, const int16 &y)
{
    if (x == -1 || y == -1)
        return ally_max;

    int16 pos = x + sz*y;
    if (grid[pos] != -cell::bad && grid[pos] > 0 && (ally_max == -1 || grid[pos] > grid[ally_max]))
        ally_max = pos;
    return ally_max;
}

void goban::turn(const int16 &x, const int16 &y, const int16 &p)
{
    int16 pos = x + sz*y;
    if (p == -1) {
        if (grid[pos] != 0)
            std::cerr << get_msg("error_here_not_free") << std::endl;
        else {
            grid[pos].val = cell::here;
            print();
        }
        return;
    }
    if (grid[pos] != 0)
        throw std::invalid_argument("not free spot");
    grid[pos].val = p == 1 ? -1 : 1;
    try {
        check_value(*this, x, y, p == 1);
    } catch (GameEnd &e) {
        throw;
    }
}

void goban::print() {
    std::cout << std::string("+") + std::string(sz*2 +1, '-') + "+" << std::endl;
    int16 v;
    for (int i = 0; i < sz*sz; i++) {
        v = grid[i];
        if (i % sz == 0)
            std::cout << "| ";
        switch (v) {
            case 0:
                std::cout << ". ";
                break;
            case cell::here:
                std::cout << "X ";
                grid[i] = 0;
                break;
            case cell::win:
                std::cout << "O ";
                break;
            case -cell::win:
                std::cout << "# ";
                break;
            default:
                if ((v > 0 && v != -cell::bad) || v == cell::bad)
                    std::cout << "o ";
                else if ((v < 0 && v != cell::bad) || v == -cell::bad)
                    std::cout << "* ";
        }
        if (i % sz == sz-1)
            std::cout << "|" << std::endl;
    }
    std::cout << std::string("+") + std::string(sz*2 +1, '-') + "+" << std::endl;
}
