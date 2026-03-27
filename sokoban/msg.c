#include <stdio.h>
#include <string.h>
#include "sokoban.h"

const struct msg_list msg_list[] = {
    {"win", {
        {"fr", "gagné\n"},
        {"en", "win\n"}
    }}, {"stuck", {
        {"fr", "bloqué\n"},
        {"en", "stuck\n"}
    }}, 
    
    {"error_parameter", {
        {"fr", "ERREUR : 1 ou 2 parametres attendus, il y en %i\n"},
        {"en", "ERROR: 1 or 2 parameters needed got %i\n"}
    }}, {"error_lang", {
        {"fr", "ERREUR : cette langue n'est pas disponible : %s\n"},
        {"en", "ERROR: that language is not available: %s\n"}
    }}, {"error_file_not_openable", {
        {"fr", "ERREUR : impossible d'ouvrir \"%s\"\n"},
        {"en", "ERROR: couldn't open \"%s\"\n"}
    }}, {"error_small_file", {
        {"fr", "ERREUR : le fichier est trop petit\n"},
        {"en", "ERROR: file is too small\n"}
    }}, {"error_big_file", {
        {"fr", "ERREUR : le fichier est trop volumineux\n"},
        {"en", "ERROR: file is too large\n"}
    }}, {"error_file_not_readable", {
        {"fr", "ERREUR : impossible de lire le fichier\n"},
        {"en", "ERROR: couldn't read file\n"}
    }}, {"error_invalid_charactere", {
        {"fr", "ERREUR : le caractère \'%c\' est invalide\n"},
        {"en", "ERROR: charactere \'%c\' is invalid\n"}
    }}, {"error_many_player", {
        {"fr", "ERREUR : il y a trop de joueurs sur cette carte\n"},
        {"en", "ERROR: there is too many player on that map\n"}
    }}, {"error_no_player", {
        {"fr", "ERREUR : il n'y a pas de joueur sur cette carte\n"},
        {"en", "ERROR: there is no player on that map\n"}
    }}, {"error_not_enough_box", {
        {"fr", "ERREUR : il n'y a pas assez de caisses sur cette carte\n"},
        {"en", "ERROR: there is not enough box on that map\n"}
    }}, {"error_general", {
        {"fr", "une erreur s'est produite\n"},
        {"en", "an error occurred\n"}
    }}, {"error_memory", {
        {"fr", "ERREUR DE MÉMOIRE : une erreur s'est produite\n"},
        {"en", "MEMORY ERROR: an error occurred\n"}
    }}, {NULL, {}}
};

char *langs[LANG_NUM] = {"fr", "en"};
char lang[2] = "fr";

void set_lang(const char *str)
{
    for (int i = 0; i < LANG_NUM; i++)
        if (strcmp(str, langs[i]) == 0) {
            strcpy(lang, str);
            return;
        }

    fprintf(stderr, get_msg("error_lang"), str);
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
