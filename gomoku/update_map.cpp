/*
** EPITECH PROJECT, 2022
** grid_value
** File description:
** grid_value
*/

#include <iostream>
#include "board.hpp"

void update_arround(goban &gboard, int16 size, int16 x, int16 y, cell::direction &dr, int16 sign)
{
    int16 dr_x = dr&1;
    int16 dr_y = dr < 0 ? -1 : dr >> 1;
    int16 v = 0;
    int16 sign1 = sign;
    int16 sign2 = sign;
    bool check1 = true;
    bool check2 = true;

    for (int16 i = 1; i < 5; i++) {
        check1 = check1 && x+ dr_x*i < size && y+ dr_y*i >= 0 && y+ dr_y*i < size;
        if (check1) {
            cell &cell = gboard(x+ dr_x*i, y+ dr_y*i);
            v = cell;
            if (sign1 == sign && v*sign1 != cell::bad && v*sign1 < 0)
                sign1 *= -1;
            v *= sign1;
            check1 = v != -cell::bad && v >= 0;
            if (check1 && v > 0) {
                find_max(gboard, x+ dr_x*i, y+ dr_y*i, dr, v, sign1, false);
                cell.set_max(dr);
                cell = cell.find_best()*sign1;
            }
        }

        check2 = check2 && x- dr_x*i >= 0 && y- dr_y*i >= 0 && y- dr_y*i < size;
        if (check2) {
            cell &cell = gboard(x- dr_x*i, y- dr_y*i);
            v = cell;
            if (sign2 == sign && v*sign2 != cell::bad && v*sign2 < 0)
                sign2 *= -1;
            v *= sign2;
            check2 = v != -cell::bad && v >= 0;
            if (check2 && v > 0) {
                find_max(gboard, x- dr_x*i, y- dr_y*i, dr, v, sign2, false);
                cell.set_max(dr);
                cell = cell.find_best()*sign2;
            }
        }

        if (!check1 && !check2)
            break;
    }
    int16 highest = gboard.ally_highest();
    if (gboard[highest] == cell::bad) {
        int16 pos = gboard.find_highest(1, highest);
        gboard.ally_highest(pos%size, pos/size);
    }
    highest = gboard.ennemi_highest();
    if (gboard[highest] == -cell::bad) {
        int16 pos = gboard.find_highest(-1, highest);
        gboard.ennemi_highest(pos%size, pos/size);
    }
}

void find_max(goban &gboard, int16 x, int16 y, cell::direction dr, int16 &best, int16 sign, bool update)
{
    int16 comb[] = {1, 2, 4, 8, 16};
    int16 dr_x = dr&1;
    int16 dr_y = dr < 0 ? -1 : dr >> 1;
    int16 size = gboard.size();
    int16 v1 = 0;
    int16 v2 = 0;
    for (int16 i = 1; i < 5; i++) {
        v1 = (v1 >= 0 && x+ dr_x*i < size && y+ dr_y*i >= 0 && y+ dr_y*i < size) ? gboard(x+ dr_x*i, y+ dr_y*i)*sign : -1;
        if (v1 == 15 || v1 == -15)
            v1 *= -1;
        if (comb[1] >= 0 && i == 1)
            comb[1] = v1 < 0 ? -1 : v1 == 0 ? comb[1] : comb[1] | 1;
        if (comb[2] >= 0 && i <= 2)
            comb[2] = v1 < 0 ? -1 : v1 == 0 ? comb[2] : comb[2] | (1 << (2-i));
        if (comb[3] >= 0 && i <= 3)
            comb[3] = v1 < 0 ? -1 : v1 == 0 ? comb[3] : comb[3] | (1 << (3-i));
        if (comb[4] >= 0)
            comb[4] = v1 < 0 ? -1 : v1 == 0 ? comb[4] : comb[4] | (1 << (4-i));
        v2 = (v2 >= 0 && x- dr_x*i >= 0 && y- dr_y*i >= 0 && y- dr_y*i < size) ? gboard(x- dr_x*i, y- dr_y*i)*sign : -1;
        if (v2 == 15 || v2 == -15)
            v2 *= -1;
        if (comb[0] >= 0)
            comb[0] = v2 < 0 ? -1 : v2 == 0 ? comb[0] : comb[0] | (1 << i);
        if (comb[1] >= 0 && i <= 3)
            comb[1] = v2 < 0 ? -1 : v2 == 0 ? comb[1] : comb[1] | (1 << (i+1));
        if (comb[2] >= 0 && i <= 2)
            comb[2] = v2 < 0 ? -1 : v2 == 0 ? comb[2] : comb[2] | (1 << (i+2));
        if (comb[3] >= 0 && i == 1)
            comb[3] = v2 < 0 ? -1 : v2 == 0 ? comb[3] : comb[3] | (1 << 4);
        if ((comb[0] & comb[1] & comb[2] & comb[3] & comb[4]) == -1)
            break;
    }
    std::vector<cell::comb> score = convert(comb);
    gboard(x, y).score(score, dr);
    int16 max = MAX(MAX(MAX(score[0], score[1]), MAX(score[2], score[3])), score[4]);
    if (max > best) {
        best = max;
        gboard(x, y).toward(dr);
    }
    if (update) {
        update_arround(gboard, size, x, y, dr, sign);
        if (best == cell::win) {
            gboard(x, y) = max*sign;
            if (sign == 1)
                throw GameEnd(GameEnd::p2_won);
            throw GameEnd(GameEnd::p1_won);
        }
    }
}

void check_value(goban &gboard, int16 x, int16 y, bool p1)
{
    int16 sign = p1 ? -1 : 1;
    int16 max = cell::bad;
    try {
        find_max(gboard, x, y, cell::horizontal, max, sign);
        find_max(gboard, x, y, cell::vertical, max, sign);
        find_max(gboard, x, y, cell::dr_diagonal, max, sign);
        find_max(gboard, x, y, cell::ur_diagonal, max, sign);
    } catch (GameEnd &e) {
        throw;
    }
    gboard(x, y) = max*sign;
    p1 ? gboard.ennemi_highest(x, y) : gboard.ally_highest(x, y);
    for (int pos = 0, size = gboard.size(); pos < size*size; pos++)
        if (gboard[pos] == 0)
            return;
    throw GameEnd(GameEnd::tie);
}
