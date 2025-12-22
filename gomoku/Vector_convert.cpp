/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** convert
*/

#include <vector>
#include "board.hpp"

std::vector<cell::comb> convert(int16 tab[5])
{
    std::vector<cell::comb> comb(5);

    for (int i = 0; i < 5; i++) {
        switch (tab[i]) {
            case -1:
                comb[i] = cell::bad;
                break;
            case 1:
            case 2:
            case 4:
            case 8:
            case 16:
                comb[i] = cell::simple;
                break;
            case 3:
            case 6:
            case 12:
            case 24:
                comb[i] = cell::twins;
                break;
            case 5:
            case 10:
            case 20:
                comb[i] = cell::stwins;
                break;
            case 7:
            case 14:
            case 28:
                comb[i] = cell::triple;
                break;
            case 9:
            case 18:
                comb[i] = cell::sstwins;
                break;
            case 11:
            case 13:
            case 22:
            case 26:
                comb[i] = cell::striple;
                break;
            case 15:
            case 30:
                comb[i] = cell::quadra;
                break;
            case 17:
                comb[i] = cell::ssstwins;
                break;
            case 19:
            case 25:
                comb[i] = cell::sstriple;
                break;
            case 21:
                comb[i] = cell::s_striple;
                break;
            case 23:
            case 29:
                comb[i] = cell::squadra;
                break;
            case 27:
                comb[i] = cell::msquadra;
                break;
            case 31:
                comb[i] = cell::win;
                break;
        }
    }
    return comb;
}
