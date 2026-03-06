/*
** EPITECH PROJECT, 2022
** gomoku
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include <algorithm>
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

void change_lang(const std::string &str, bool print = true) {
    if (str == msg::lang) {
        if (print)
            std::cout << get_msg("no_change_lang") << std::endl;
    } else {
        msg::lang = str;
        if (print)
            std::cout << get_msg("change_lang") << std::endl;
    }
}

int read_input(const int16 size, int16 &x, int16 &y, const int16 pl)
{
    std::string str;

    if (pl == 0)
        std::cout << get_msg("player_turn");
    else
        std::cout << get_msg("multi_player_turn", pl);
    std::getline(std::cin, str);

    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
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
        change_lang(str);
        return 3;
    }

    auto find_coord = [size, &x, &y](std::string &str){
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

void print_error_all_lang(const std::array<std::string, msg::lang_num> &list) {
    for (const auto &msg : list) {
        std::cerr << msg << std::endl;
    }
}

bool check_param(int ac, char **av, int &ind, bool &multi) {
    if (std::strncmp(av[ind], "-lang=", 6) == 0) {
        if (is_lang(av[ind]+6)) {
            change_lang(av[ind]+6, false);
        } else {
            print_error_all_lang(get_msg_all_lang("error_lang", av[ind]+6));
            return false;
        }
    } else if (std::strcmp(av[ind], "-multi") == 0) {
        multi = true;
    } else if (*av[ind] == '-') {
        std::cerr << get_msg("error_option", av[ind]) << std::endl;
        return false;
    } else {
        return true;
    }
    if (++ind == ac){
        std::cerr << get_msg("error_missing_parameter") << std::endl;
        return false;
    }
    return check_param(ac, av, ind, multi);
}

int main(int ac, char **av)
{
    if (ac < 2){
        print_error_all_lang(get_msg_all_lang("error_missing_parameter"));
        return 1;
    }
    std::sort(av+1, av+ac, [](char *str1, char *str2){
        if (std::strncmp(str1, "-lang=", 6) == 0 && std::strncmp(str2, "-lang=", 6) != 0)
            return true;
        return (std::strcmp(str1, str2) < 0);
    });

    bool multi = false;
    int ind = 1;
    if (!check_param(ac, av, ind, multi))
        return 1;

    int16 size;
    try {
        size = getnbr<__int8_t>(av[ind]);
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

    try {
        goban gboard(size);
        return game_loop(gboard, multi);
    } catch (...) {
        std::cerr << get_msg("error_memory") << std::endl;
        return 1;
    }
}
