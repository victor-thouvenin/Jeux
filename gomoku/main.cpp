/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "include/board.hpp"
#include "include/game_end.hpp"
#include "getnbr.hpp"

bool is_lang(const std::string &str) {
    if (str == msg::lang)
        return true;
    auto begin = msg::langs.begin();
    auto end = msg::langs.end();
    while (*begin != str && begin != end) {
        ++begin;
    }
    return begin != end;
}

void print_lang() {
    std::string list;
    auto begin = msg::langs.begin();
    auto end = msg::langs.end();
    while (begin != end) {
        list += *begin;
        if (++begin != end)
            list += ", ";
    }
    std::cout << list << std::endl;
}

int read_input(const int16 size, int16 &x, int16 &y, const int16 pl)
{
    std::string str;

    if (pl == 0)
        std::cout << get_msg("player_turn");
    else
        std::cout << get_msg("multi_player_turn", pl);
    std::getline(std::cin, str);

    if (str == "")
        throw std::invalid_argument(get_msg("error_coordinate_format"));
    if (str == get_msg("start"))
        return 2;
    if (str == get_msg("end"))
        throw GameEnd(GameEnd::tie, "");
    if (str == get_msg("lang")) {
        print_lang();
        return 3;
    } if (is_lang(str.c_str())) {
        if (str == msg::lang)
            std::cout << get_msg("no_change_lang") << std::endl;
        else {
            msg::lang = str;
            std::cout << get_msg("change_lang") << std::endl;
        }
        return 3;
    }

    auto find_coord = [size, &x, &y](std::string &str){
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ')+1);
        size_t i = str.find(' ');
        if (i == std::string::npos)
            throw std::invalid_argument(get_msg("error_coordinate_format"));

        std::string lstr = str.substr(0, i);
        std::string rstr = str.substr(str.rfind(' ')+1);
        try {
            x = getnbr<int16>(lstr.c_str())-1;
            y = getnbr<int16>(rstr.c_str())-1;
        } catch (...) {
            throw std::invalid_argument(get_msg("error_coordinate_format"));
        }
        if (x >= size || x < 0 || y >= size || y < 0)
            throw std::invalid_argument(get_msg("error_coordinate_format"));
    };
    size_t i = str.find(get_msg("where"));
    size_t i2 = str.find(" ", i);
    if (i != std::string::npos) {
        try {
            find_coord(str.erase(0, i2));
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

int game_loop(goban &gboard, const bool multi) {
    int16 x, y;
    int16 pl = 0;
    gboard.print();
    while (1) {
        try {
            switch (read_input(gboard.size(), x, y, pl+multi)) {
                case 1:
                    gboard.turn(x, y, -1);
                    continue;
                case 2:
                    if (multi)
                        std::cerr << get_msg("error_multiplayer_AI") << std::endl;
                    else if (gboard.ally_highest() != -1 || gboard.ennemi_highest() != -1)
                        std::cerr << get_msg("error_game_began") << std::endl;
                    else {
                        x = gboard.size()/2, y = gboard.size()/2;
                        gboard.turn(x, y, 0);
                        std::cout << get_msg("AI_plays", y+1, x+1) << std::endl;
                        gboard.print();
                    }
                    continue;
                case 3:
                    continue;
            }
        } catch (GameEnd &e) {
            return 0;
        } catch (std::exception &e) {
            if (std::cin.eof()) {
                std::cout << std::endl;
                return 0;
            }
            std::cerr << get_msg("error_coordinate_range", gboard.size()) << std::endl;
            continue;
        }
        try {
            gboard.turn(x, y, pl+1);
        } catch (std::invalid_argument &e) {
            std::cerr << get_msg("error_not_free_spot") << std::endl;
            continue;
        } catch (GameEnd &e) {
            if (e.state() == GameEnd::error) {
                std::cerr << e.how() << std::endl;
                return 1;
            }
            gboard.print();
            std::cout << (multi || e.state() == GameEnd::tie ? e.how() : get_msg("AI_lost")) << std::endl;
            return 0;
        }
        if (!multi) {
            gboard.print();
            std::cout << get_msg("AI_turn");
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
        gboard.print();
        pl ^= multi;
    }
}

int main(int ac, char **av)
{
    int16 size;
    if (ac < 2){
        std::cerr << get_msg("error_missing_parameter") << std::endl;
        return 1;
    }
    try {
        size = getnbr<__int8_t>(av[1]);
    } catch (std::out_of_range &e) {
        std::cerr << get_msg("error_big_grid") << std::endl;
        return 1;
    } catch (std::invalid_argument &e) {
        std::cerr << get_msg("error_not_number_size") << std::endl;
        return 1;
    } if (size < 0) {
        std::cerr << get_msg("error_not_number_size") << std::endl;
        return 1;
    } if (size < 5) {
        std::cerr << get_msg("error_small_grid") << std::endl;
        return 1;
    }

    if (ac > 2 && std::strcmp(av[2], "-multi") != 0) {
        std::cerr << get_msg("error_option", av[2]) << std::endl;
        return 1;
    }
    try {
        goban gboard(size);
        return game_loop(gboard, ac > 2);
    } catch (...) {
        std::cerr << get_msg("error_memory") << std::endl;
        return 1;
    }
}
