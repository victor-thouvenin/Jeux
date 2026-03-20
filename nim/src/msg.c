#include <stdio.h>
#include <string.h>
#include "../nim.h"

const struct msg_list msg_list[] = {
    {"command_stop", {
        {"en", "end"},
        {"fr", "stop"}
    }}, {"ask_line", {
        {"en", "Line: "},
        {"fr", "Ligne : "}
    }}, {"ask_match", {
        {"en", "Matches: "},
        {"fr", "Allumettes : "}
    }},

    {"change_lang", {
        {"en", "changing language to english"},
        {"fr", "langue changée en français"}
    }}, {"no_change_lang", {
        {"en", "the game is already english"},
        {"fr", "le jeu est déjà en français"}
    }},

    {"player_basic_name", {
        {"en", "player"},
        {"fr", "joueur"}
    }}, {"player_turn", {
        {"en", "\nYour turn:"},
        {"fr", "\nTour du joueur :"}
    }}, {"player_played", {
        {"en", "player removed %i match(es) from line %i\n"},
        {"fr", "le joueur a retiré %i allumette(s) à la ligne %i\n"}
    }}, {"player_lost", {
        {"en", "You lost, too bad..."},
        {"fr", "Perdu, dommage ..."}
    }}, {"AI_turn", {
        {"en", "\nAI's turn..."},
        {"fr", "\nTour de l'IA ..."}
    }}, {"AI_played", {
        {"en", "AI removed %i match(es) from line %i\n"},
        {"fr", "l'IA a retiré %i allumette(s) à la ligne %i\n"}
    }}, {"AI_lost", {
        {"en", "I lost... snif... but I'll get you next time!!"},
        {"fr", "J'ai perdu ... snif ... mais je t'aurai la prochaine fois !!"}
    }},

    {"multi-player_name", {
        {"en", "player%i, enter your username (live empty for player%i): "},
        {"fr", "joueur%i, choisir un nom de joueur (joueur%i par défaut) : "}
    }}, {"multi-player_name_confirm", {
        {"en", "do you want to play as %s [y/n]: "},
        {"fr", "confirmer le nom %s [o/n] : "}
    }}, {"multi-player_name_blank_confirm", {
        {"en", "do you want to play as player%i[y/n]: "},
        {"fr", "confirmer le nom joueur%i [o/n] : "}
    }}, {"multi-player_turn", {
        {"en", "\n%s's turn:\n"},
        {"fr", "\ntour de %s\n"}
    }}, {"multi-player_played", {
        {"en", "%s removed %i match(es) from line %i\n"},
        {"fr", "%s a retiré %i allumette(s) à la ligne %i\n"}
    }}, {"multi-player_lost", {
        {"en", "\n%s lost\n"},
        {"fr", "\n%s a perdu\n"}
    }}, {"multi-player_gave_up", {
        {"en", "\n%s gave up\n"},
        {"fr", "\n%s a quitté la partie\n"}
    }}, {"multi-players_win", {
        {"en", "\n%s win\n"},
        {"fr", "\n%s a gagné\n"}
    }}, {"multi-players_remaining", {
        {"en", "\n%i players remaining\n\n"},
        {"fr", "\n%i joueurs restants\n\n"}
    }},

    {"error_name_taken", {
        {"en", "this name is not available\n"},
        {"fr", "ce nom n'est pas disponible\n"}
    }}, {"error_input", {
        {"en", "Error: invalid input (positive integer expected)\n"},
        {"fr", "Erreur : entrée invalide (entier positif attendu)\n"}
    }}, {"error_line_out_of_range", {
        {"en", "Error: this line is out of range\n"},
        {"fr", "Erreur : cette ligne est en dehors de la grille\n"}
    }}, {"error_no_remove", {
        {"en", "Error: you have to remove at least one match\n"},
        {"fr", "Erreur : retirer au minimum une allumette\n"}
    }}, {"error_too_much_remove", {
        {"en", "Error: you cannot remove more than %u matches per turn\n"},
        {"fr", "Erreur : retirer au maximum %u allumette\n"}
    }}, {"error_not_enough_matches", {
        {"en", "Error: not enough matches on this line\n"},
        {"fr", "Erreur : il n'y a pas assez d'allumettes sur cette ligne\n"}
    }}, {"error_memory", {
        {"en", "an error occured\n"},
        {"fr", "une erreur s'est produite\n"}
    }}, {"error_general_try_again", {
        {"en", "an error occured, please try again\n"},
        {"fr", "une erreur s'est produite, réessayer\n"}
    }}, {"error_general", {
        {"en", "an error occured\n"},
        {"fr", "une erreur s'est produite\n"}
    }},

    {"error_parameter", {
        {"en", "ERROR: between 1 and 3 parameters (excluding options) needed got %i\n"},
        {"fr", "Erreur : entre 1 et 3 parametres (hors options) attendus, il y en %i\n"}
    }}, {"error_lang", {
        {"fr", "ERREUR : cette langue n'est pas disponible : %s\nles langues disponibles sont :\n"},
        {"en", "ERROR: that language is not available: %s\nthe available languages are:\n"}
    }}, {"error_option", {
        {"fr", "ERREUR : option inconnue : %s\n"},
        {"en", "ERROR: unknown option: %s\n"}
    }}, {"error_line", {
        {"en", "ERROR: number of line must be a integer between 2 and 99\n"},
        {"fr", "Erreur : le nombre de lignes doit être un entier entre 2 et 99\n"}
    }}, {"error_match", {
        {"en", "ERROR: maximum match removal number must be a integer greater than 1\n"},
        {"fr", "Erreur : le nombre maximal allumettes à retirer par tour doit être un entier supérieur à 1\n"}
    }}, {"error_multi", {
        {"en", "ERROR: number of player must be a integer between 1 and 9\n"},
        {"fr", "Erreur : le nombre de joueur doit être un entier entre 1 et 9\n"}
    }}, {NULL, {}}
};

char lang[2] = "fr";
char *langs[LANG_NUM] = {"fr", "en"};

void print_lang()
{
    int i = 0;
    while (i < LANG_NUM) {
        fputs(langs[i], stdout);
        fputs(++i < LANG_NUM ? ", " : "\n", stdout);
    }
}

int is_lang(char *str)
{
    if (strcmp(lang , str) == 0)
        return 1;

    int i = 0;
    while (i < LANG_NUM) {
        if (strcmp(langs[i++], str) == 0)
            return 1;
    }
    return 0;
}

void change_lang(char *str, int b)
{
    if (strcmp(lang, str) == 0) {
        if (b)
            puts(get_msg("no_change_lang"));
    } else {
        strcpy(lang, str);
        if (b)
            puts(get_msg("change_lang"));
    }
}

const char *get_msg(const char *str) {
    int i = 0;
    while (msg_list[i].ind != NULL) {
        if (strcmp(msg_list[i].ind, str) == 0)
            break;
        ++i;
    }
    if (msg_list[i].ind == NULL)
        return "";

    int j = 0;
    while (j < LANG_NUM) {
        if (strcmp(msg_list[i].list[j].lang, lang) == 0)
            break;
        ++j;
    }
    if (j == LANG_NUM)
        return "";

    return msg_list[i].list[j].msg;
}