#pragma once

#define DEFAULT_LANG "fr"

#include <array>
#include <cstring>
#include <string>

namespace msg {
    static const int lang_num = 2;
    static std::string lang = DEFAULT_LANG;
    static constexpr const std::array<const std::string, lang_num> langs{"fr", "en"};

    struct msg {
        const std::string lang;
        const char *text;
        bool operator!=(const std::string &str) const { return lang != str; };
    };

    template<int lang_num>
    struct lang_list {
        const char *ind;
        const std::array<msg, lang_num> list;
        bool operator!=(const char *str) const { return std::strcmp(str, ind) != 0; };
    };

    static const int msg_num = 29;
    static constexpr const std::array<lang_list<lang_num>, msg_num> msg_list{
        "start", {
            {{"fr", "commence"},
            {"en", "begin"}}},
        "end", {
            {{"fr", "stop"},
            {"en", "end"}}},
        "where", {
            {{"fr", "où"},
            {"en", "where"}}},
        "lang", {
            {{"fr", "langue"},
            {"en", "language"}}},

        "no_change_lang", {
            {{"fr", "le jeu est déjà en français"},
            {"en", "the game is already english"}}},
        "change_lang", {
            {{"fr", "langue changée en français"},
            {"en", "changing language to english"}}},
        "player_turn", {
            {{"fr", "tour du joueur > "},
            {"en", "your turn > "}}},
        "multi_player_turn", {
            {{"fr", "tour du joueur {} > "},
            {"en", "player {}'s turn > "}}},
        "player1_win", {
            {{"fr", "le joueur 1 a gagné. bravo!"},
            {"en", "player 1 won. good job!"}}},
        "player2_win", {
            {{"fr", "le joueur 2 a gagné. bravo!"},
            {"en", "player 2 won. good job!"}}},
        "AI_turn", {
            {{"fr", "tour de l'IA > "},
            {"en", "AI's turn > "}}},
        "AI_plays", {
            {{"fr", "l'IA a joué {}, {}"},
            {"en", "AI plays {}, {}"}}},
        "AI_won", {
            {{"fr", "j'ai gagné. mwahaha"},
            {"en", "i won. mwahaha"}}},
        "AI_lost", {
            {{"fr", "j'ai perdu. snif"},
            {"en", "i lost. huuuuuh"}}},
        "tie", {
            {{"fr", "match nul"},
            {"en", "it's a tie"}}},

        "error_coordinate_format", {
            {{"fr", "mauvais format de coordonnées"},
            {"en", "wrong coordinate format"}}},
        "error_multiplayer_AI", {
            {{"fr", "il n'y a pas d'IA en mode multijoueur"},
            {"en", "no AI in multiplayer mode"}}},
        "error_game_began", {
            {{"fr", "la partie a déjà commencé"},
            {"en", "game has already began"}}},
        "error_coordinate_range", {
            {{"fr", "ERREUR: les coordonnées doivent être des nombres entre 1 et {} au format \"x y\""},
            {"en", "ERROR: the coordinates have to be numbers between 1 and {} in format \"x y\""}}},
        "error_not_free_spot", {
            {{"fr", "ERREUR: cette case n'est pas libre, action impossible"},
            {"en", "ERROR: that spot isn't free, you can't play here"}}},
        "error_here_not_free", {
            {{"fr", "cette case n'est pas libre"},
            {"en", "that spot isn't free"}}},
        "error_general", {
            {{"fr", "une erreur s'est produite"},
            {"en", "an error occurred"}}},

        "error_missing_parameter", {
            {{"fr", "ERREUR : taille de la grille manquante"},
            {"en", "ERROR: grid size is missing"}}},
        "error_big_grid", {
            {{"fr", "ERREUR : taille non prise en charge : grille trop grande"},
            {"en", "ERROR: unsupported size: grid is too large"}}},
        "error_small_grid", {
            {{"fr", "ERREUR : taille non prise en charge : grille trop petite"},
            {"en", "ERROR: unsupported size: grid is too small"}}},
        "error_not_number_size", {
            {{"fr", "ERREUR : taille non prise en charge : la taille doit être un nombre entier positif"},
            {"en", "ERROR: unsupported size: size must be a positive integer"}}},
        "error_option", {
            {{"fr", "ERREUR : option inconnue : {}"},
            {"en", "ERROR: unknown option: {}"}}},
        "error_lang", {
            {{"fr", "ERREUR : cette langue n'est pas disponible : {}"},
            {"en", "ERROR: that language is not available: {}"}}},
        "error_memory", {
            {{"fr", "ERREUR DE MÉMOIRE : impossible de créer le plateau"},
            {"en", "MEMORY ERROR: couldn't create the board"}}},
    };
}

static std::string get_fmt_msg(std::string str) {
    return str;
}

template<typename T, typename... Args>
std::string get_fmt_msg(std::string &&str, T arg, Args&&... args) {
    auto i = str.find('{');
    while (i != std::string::npos && str[i+1] == '{') {
        i = str.find('{', i+2);
    }
    if (i == std::string::npos)
        return str;
    std::string fmt_msg = str.substr(0, i);
    if constexpr (std::is_integral<T>())
        fmt_msg += std::to_string(arg);
    else
        fmt_msg += arg;
    return fmt_msg + get_fmt_msg(str.substr(str.find('}', i+1)+1), args...);
}

template<typename... Args>
std::string get_msg(const char *ind, Args&&... args) {
    auto begin = msg::msg_list.begin();
    auto end = msg::msg_list.end();
    while (begin != end && *begin != ind) {
        ++begin;
    }
    if (begin == end) 
        return "";

    auto b = begin->list.begin();
    auto e = begin->list.end();
    while (*b != msg::lang && b != e) {
        ++b;
    }
    if (b == e)
        return "";
    return get_fmt_msg(b->text, args...);
};

template<typename... Args>
std::array<std::string, msg::lang_num> get_msg_all_lang(const char *ind, Args&&... args) {
    auto begin = msg::msg_list.begin();
    auto end = msg::msg_list.end();
    while (begin != end && *begin != ind) {
        ++begin;
    }
    std::array<std::string, msg::lang_num> list;
    if (begin == end) 
        return list;

    auto b = begin->list.begin();
    auto e = begin->list.end();
    int i = 0;
    while (b != e) {
        list[i++] = get_fmt_msg(b->text, args...);
        ++b;
    }
    return list;
}
