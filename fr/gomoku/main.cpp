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
        std::cout << "tour du joueur > ";
    else
        std::cout << "tour du joueur " << pl << " > ";
    std::getline(std::cin, str);

    if (str == "")
        throw std::invalid_argument("mauvais format de coordonnées");
    if (str == "commence")
        return 2;
    if (str == "stop")
        throw GameEnd(GameEnd::tie, "");

    auto find_coord = [size, &x, &y](std::string &str){
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ')+1);
        size_t i = str.find(' ');
        if (i == std::string::npos)
            throw std::invalid_argument("mauvais format de coordonnées");

        std::string lstr = str.substr(0, i);
        std::string rstr = str.substr(str.rfind(' ')+1);
        try {
            x = getnbr<int16>(lstr.c_str())-1;
            y = getnbr<int16>(rstr.c_str())-1;
        } catch (...) {
            throw std::invalid_argument("mauvais format de coordonnées");
        }
        if (x >= size || x < 0 || y >= size || y < 0)
            throw std::invalid_argument("mauvais format de coordonnées");
    };
    size_t i = str.find("où");
    if (i != std::string::npos) {
        try {
            find_coord(str.erase(0, i+3));
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
                        std::cerr << "il n'y a pas d'IA en mode multijoueur" << std::endl;
                    else if (gboard.ally_highest() != -1 || gboard.ennemi_highest() != -1)
                        std::cerr << "la partie a déjà commencé" << std::endl;
                    else {
                        x = gboard.size()/2, y = gboard.size()/2;
                        gboard.turn(x, y, 0);
                        std::cout << "l'IA a joué " << y+1 << ',' << x+1 << std::endl;
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
            std::cerr << "ERREUR: les coordonnées doivent être des nombres entre 1 et " << gboard.size() << " au format \"x y\"" << std::endl;
            continue;
        }
        try {
            gboard.turn(x, y, pl+1);
        } catch (std::invalid_argument &e) {
            std::cerr << "ERREUR: cette case n'est pas libre, action impossible" << std::endl;
            continue;
        } catch (GameEnd &e) {
            if (e.state() == GameEnd::error) {
                std::cerr << e.how() << std::endl;
                return 1;
            }
            gboard.print();
            std::cout << (multi || e.state() == GameEnd::tie ? e.how() : "j'ai perdu. snif") << std::endl;
            return 0;
        }
        if (!multi) {
            gboard.print();
            std::cout << "tour de l'IA > ";
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
        std::cerr << "ERREUR : taille de la grille manquant" << std::endl;
        return 1;
    }
    try {
        size = getnbr<__int8_t>(av[1]);
    } catch (std::out_of_range &e) {
        std::cerr << "ERREUR : taille non prise en charge : grille trop grande" << std::endl;
        return 1;
    } catch (std::invalid_argument &e) {
        std::cerr << "ERREUR : taille non prise en charge : la taille doit être un nombre" << std::endl;
        return 1;
    } if (size < 5) {
        std::cerr << "ERREUR : taille non prise en charge : grille trop petite" << std::endl;
        return 1;
    }

    goban gboard;
    try {
        goban b(size);
        gboard = b;
    } catch (...) {
        std::cerr << "Erreur de mémoire : impossible de créer le plateau" << std::endl;
        return 1;
    }
    if (ac > 2) {
        if (std::strcmp(av[2], "-multi") == 0)
            return game_loop(gboard, true);
        else {
            std::cerr << "ERREUR : option inconnue : " << av[2] << std::endl;
            return 1;
        }
    }
    return game_loop(gboard, false);
}
