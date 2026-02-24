#pragma once

#include <string>
#include <map>

static std::map<std::string, std::string> msg_fr_list {
    {"player_turn", "tour du joueur "},
    {"start", "commence"},
    {"end", "stop"},
    {"where", "où"},
    {"player1_win", "le joueur 1 a gagné. bravo!"},
    {"player2_win", "le joueur 2 a gagné. bravo!"},
    {"AI_turn", "tour de l'IA > "},
    {"AI_plays", "l'IA a joué "},
    {"AI_won", "j'ai gagné. mwahaha"},
    {"AI_lost", "j'ai perdu. snif"},
    {"tie", "match nul"},

    {"error_coordinate_format", "mauvais format de coordonnées"},
    {"error_multiplayer_AI", "il n'y a pas d'IA en mode multijoueur"},
    {"error_game_began", "la partie a déjà commencé"},
    {"error_coordinate_range", "ERREUR: les coordonnées doivent être des nombres entre 1 et  au format \"x y\""},
    {"error_not_free_spot", "ERREUR: cette case n'est pas libre, action impossible"},
    {"error_here_not_free", "cette case n'est pas libre"},
    {"error_general", "une erreur s'est produite"},

    {"error_missing_parameter", "ERREUR : taille de la grille manquant"},
    {"error_big_grid", "ERREUR : taille non prise en charge : grille trop grande"},
    {"error_small_grid", "ERREUR : taille non prise en charge : grille trop petite"},
    {"error_not_number_size", "ERREUR : taille non prise en charge : la taille doit être un nombre"},
    {"error_option", "ERREUR : option inconnue : "},
    {"error_memory", "Erreur de mémoire : impossible de créer le plateau"},
};

static std::map<std::string, std::string> msg_list = msg_fr_list;
