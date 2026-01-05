/*
** EPITECH PROJECT, 2022
** grid_value
** File description:
** grid_value
*/

#include <iostream>
#include "board.hpp"

void find_best_move(goban &gboard, int16 pos, cell &cell, int16 comb, int16 val)
{
    int16 size = gboard.size();
    cell::direction &dr = cell.toward();
    int16 x = pos%size;
    int16 y = pos/size;
    int16 dr_x = dr&1;
    int16 dr_y = dr < 0 ? -1 : dr >> 1;
    int16 max = cell.max();

    auto play_pos = [&gboard, &size, &x, &y, &dr_x, &dr_y](int16 dlt, int16 dlt2) {
        x += dlt*dr_x;
        y += dlt*dr_y;
        if (x < 0 || x >= size || y < 0 || y >= size || gboard(x, y) != 0) {
            x += (dlt2-dlt)*dr_x;
            y += (dlt2-dlt)*dr_y;
        }
    };

    switch (comb) {
    	case cell::quadra:
            gboard(x+ max*dr_x, y+ max*dr_y) == val ? play_pos(max+1, max-4) : play_pos(max, max-5);
    		break;
    	case cell::squadra:
            play_pos(max-1, max-3);
    		break;
    	case cell::msquadra:
            x += (max-2)*dr_x;
            y += (max-2)*dr_y;
    		break;

    	case cell::triple:
            if (gboard(x+ (max-1)*dr_x, y+ (max-1)*dr_y) != val)
                play_pos(max-1, max-5);
            else if (gboard(x+ max*dr_x, y+ max*dr_y) != val)
                play_pos(max, max-4);
            else {
                play_pos(max+1, max-3);
            }
     		break;
     	case cell::striple:
            gboard(x+ max*dr_x, y+ max*dr_y) == val ? play_pos(max-1, max-2) : play_pos(max-2, max-3);
     		break;
     	case cell::s_striple:
            x += (max-1)*dr_x;
            y += (max-1)*dr_y;
     		break;
     	case cell::sstriple:
            x += (max-2)*dr_x;
            y += (max-2)*dr_y;
    		break;

    	case cell::twins:
            if (max == 0 || (max == 1 && gboard(x+ max*dr_x, y+ max*dr_y) == val))
                play_pos(max+1, max-2);
            else if (max == 1 || (max == 2 && gboard(x+ (max-1)*dr_x, y+ (max-1)*dr_y) == val))
                play_pos(max, max-3);
            else if (max == 2 || (max == 3 && gboard(x+ (max-2)*dr_x, y+ (max-2)*dr_y) == val))
                play_pos(max-1, max-4);
            else {
                play_pos(max-2, max-5);
            }
     		break;
     	case cell::stwins:
            if (max == 0 || (max == 2 && gboard(x+ max*dr_x, y+ max*dr_y) == val)) {
                x += (max-1)*dr_x;
                y += (max-1)*dr_y;
            } else if (max == 1 || max == 3) {
                x += (max-2)*dr_x;
                y += (max-2)*dr_y;
            } else {
                x += (max-3)*dr_x;
                y += (max-3)*dr_y;
            }
     		break;
     	case cell::sstwins:
            x += (max-2)*dr_x;
            y += (max-2)*dr_y;
     		break;
     	case cell::ssstwins:
            x += (max-2)*dr_x;
            y += (max-2)*dr_y;
    		break;

    	case cell::simple:
            play_pos(1, -1);
            break;

        default :
            if (gboard(gboard.size()/2, gboard.size()/2) == 0) {
                x = gboard.size()/2, y = gboard.size()/2;
                break;
            }
            for (pos = 0; pos < size*size; pos++) {
                if (gboard[pos] == 0) {
                    x = pos%size;
                    y = pos/size;
                    break;
                }
            }
    }
    try {
        gboard.turn(x, y, 0);
        std::cout << x+1 << ' ' << y+1 << std::endl;
    } catch (std::invalid_argument &e) {
        return;
    } catch (GameEnd &e) {
        std::cout << x+1 << ' ' << y+1 << std::endl;
        if (e.state() == GameEnd::p2_won)
            throw GameEnd(GameEnd::p2_won, "j'ai gagné. mwahaha");
        else
            throw;
    }
}

void ai_plays(goban &gboard)
{
    int16 apos = gboard.ally_highest();
    int16 epos = gboard.ennemi_highest();
    cell acell;
    cell ecell;
    int16 amax = cell::bad;
    int16 emax = -cell::bad;

    if (apos != -1) {
        acell = gboard[apos];
        amax = acell;
    }
    if (epos != -1) {
        ecell = gboard[epos];
        emax = ecell;
    }
    try {
        if (epos != -1 && -emax > amax /* && -emax != cell::twins */)
            find_best_move(gboard, epos, ecell, -emax, emax);
        else
            find_best_move(gboard, apos, acell, amax, amax);
    } catch (GameEnd &e) {
        throw;
    }
}
