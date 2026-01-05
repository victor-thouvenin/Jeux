/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "board.hpp"
#include "getnbr.hpp"

int read_input(int16 size, int16 &x, int16 &y, int16 pl)
{
    std::string str;

    if (pl == 0)
        std::cout << "your turn > ";
    else
        std::cout << "player " << pl << "'s turn > ";
    std::getline(std::cin, str);

    if (str == "")
        throw std::invalid_argument("wrong coordinate format");
    if (str == "begin")
        return 2;
    if (str == "end")
        throw GameEnd(GameEnd::tie, "");

    auto find_coord = [size, &x, &y](std::string &str){
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ')+1);
        size_t i = str.find(' ');
        if (i == std::string::npos)
            throw std::invalid_argument("wrong coordinate format");

        std::string lstr = str.substr(0, i);
        std::string rstr = str.substr(str.rfind(' ')+1);
        try {
            x = getnbr<int16>(lstr.c_str())-1;
            y = getnbr<int16>(rstr.c_str())-1;
        } catch (...) {
            throw std::invalid_argument("wrong coordinate format");
        }
        if (x >= size || x < 0 || y >= size || y < 0)
            throw std::invalid_argument("wrong coordinate format");
    };
    size_t i = str.find("where");
    if (i != std::string::npos) {
        try {
            find_coord(str.erase(0, i+5));
        } catch (...) {
            throw;
        }
        return 1;
    }
    try {
        find_coord(str);
    } catch (...) {
        throw;
    }
    return 0;
}

int game_loop(goban &gboard, bool multi) {
    int16 x, y;
    int16 pl = 0;
    while (1) {
        gboard.print();
        try {
            switch (read_input(gboard.size(), x, y, pl+multi)) {
                case 1:
                    gboard.turn(x, y, -1);
                    continue;
                case 2:
                    if (multi)
                        std::cerr << "no AI in multiplayer mode" << std::endl;
                    else if (gboard.ally_highest() != -1 || gboard.ennemi_highest() != -1)
                        std::cerr << "game has already began" << std::endl;
                    else {
                        x = gboard.size()/2, y = gboard.size()/2;
                        gboard.turn(x, y, 0);
                        std::cout << "AI plays " << y+1 << ',' << x+1 << std::endl;
                    }
                    continue;
            }
        } catch (GameEnd &e) {
            return 0;
        } catch (std::exception &e) {
            if (std::cin.eof()) {
                std::cout << std::endl;
                return 0;
            }
            std::cerr << "ERROR: the coordinates have to be numbers between 1 and " << gboard.size() << " in format \"x y\"" << std::endl;
            continue;
        }
        try {
            gboard.turn(x, y, pl+1);
        } catch (std::invalid_argument &e) {
            std::cerr << "ERROR: that cell isn't free, you can't play here" << std::endl;
            continue;
        } catch (GameEnd &e) {
            if (e.state() == GameEnd::error) {
                std::cerr << e.how() << std::endl;
                return 1;
            }
            gboard.print();
            std::cout << (multi || e.state() == GameEnd::tie ? e.how() : "i lost. huuuuuh") << std::endl;
            return 0;
        }
        if (!multi) {
            gboard.print();
            std::cout << "AI's turn > ";
            try {
                ai_plays(gboard);
            } catch (GameEnd &e) {
                if (e.state() == GameEnd::error) {
                    std::cerr << e.how() << std::endl;
                    return 1;
                }
                gboard.print();
                std::cout << e.how() << std::endl;
                return 0;
            }
        }
        pl ^= multi;
    }
}

int main(int ac, char **av)
{
    int16 size;
    if (ac < 2){
        std::cerr << "ERROR: grid size is missing" << std::endl;
        return 1;
    }
    try {
        size = getnbr<__int8_t>(av[1]);
    } catch (std::out_of_range &e) {
        std::cerr << "ERROR: unsupported size: grid is too large" << std::endl;
        return 1;
    } catch (std::invalid_argument &e) {
        std::cerr << "ERROR: unsupported size: size must be a number" << std::endl;
        return 1;
    } if (size < 5) {
        std::cerr << "ERROR: unsupported size: grid is too small" << std::endl;
        return 1;
    }

    goban gboard;
    try {
        goban b(size);
        gboard = b;
    } catch (...) {
        std::cerr << "Memory error: couldn't create the board" << std::endl;
        return 1;
    }
    if (ac > 2) {
        if (std::strcmp(av[2], "-multi") == 0)
            return game_loop(gboard, true);
        else {
            std::cerr << "ERROR: unknown option: " << av[2] << std::endl;
            return 1;
        }
    }
    return game_loop(gboard, false);
}
