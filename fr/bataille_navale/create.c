/*
** EPITECH PROJECT, 2019
** create
** File description:
** create
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_printf/print.h"
#include "navy.h"
#include "game.h"

extern game_t game;

int set_boat(int size, int b, int e)
{
    int d = b < e ? 1 : -1;
    if (b/10 != e/10)
        d *= 10;
    while (b != e + d) {
        if (game.player[b/10][b%10] != '.') {
            dprintf(2, "ERREUR : mauvais format, 2 bateaux se chevauchent en %c%i\n", b%10 +'A', b/10 +1);
            return 0;
        }
        game.player[b/10][b%10] = size+'0';
        b += d;
    }
    return 1;
}

int nbb[4] = {0, 0, 0, 0};

int check_file(char *str, int *size, int *b, int *e)
{
    if (my_strlen(str) < 7 || str[1] != ':' || str[4] != ':' || (str[7] != '\0' && str[7] != '\n')) {
        dprintf(2, "ERREUR : mauvais format : %s\nformat attendu :\
 [taille : un chiffre]:[coordonnée1 : une lettre et un chiffre]:[coordonnée2 : une lettre et un chiffre]\n", str);
        return 0;
    }
    *size = str[0]-'0';
    if (*size < 2 || *size > 5) {
        dprintf(2, "ERREUR : mauvais format : %s\ntaille incorrecte : %i,\
 la taille doit être un nombre entre 2 et 5 (inclus)\n", str, *size);
        return 0;
    }
    nbb[*size-2] ^= 1;
    if (nbb[*size-2] == 0) {
        dprintf(2, "ERREUR : mauvais format, il y a 2 bateaux de taille %i\n", *size);
        return 0;
    }
    if (str[2] < 'A' || str[2] > 'H' || str[3] < '1' || str[3] > '8' ||
        str[5] < 'A' || str[5] > 'H' || str[6] < '1' || str[6] > '8') {
        dprintf(2, "ERREUR : mauvais format : %s\nformat de coordonnée attendu :\
 [lettre (majuscule) entre 'A' et 'H'][chiffre entre 1 et 8]\n", str);
        return 0;
    }

    *b = (str[3]-'1')*10 + str[2]-'A';
    *e = (str[6]-'1')*10 + str[5]-'A';
    if ((*e/10 == *b/10) == (*e%10 == *b%10)) {
        dprintf(2, "ERREUR : mauvais format : %s\nles bateaux doivent être en ligne droite (horizontalement ou verticalement)\
 et leurs coordonnées doivent être différentes\n", str);
        return 0;
    }
    int dif = (*e/10 - *b/10) | (*e%10 - *b%10);
    if (dif != *size-1 && -dif != *size-1) {
        dprintf(2, "ERREUR : mauvais format : %s\nla taille et les coordonnées ne correspondent pas\n", str);
        return 0;
    }
    return 1;
}

int fill_map(int fd, char *file)
{
    char str[8];
    int size = 0;
    int b = 0;
    int e = 0;
    int i = 0;

    while (i < 4) {
        read(fd, str, 8);
        if (!check_file(str, &size, &b, &e) || !set_boat(size, b, e)) {
            dprintf(2, "dans %s à la ligne %i\n", file, i+1);
            return 0;
        }
        ++i;
    }
    if (i != 4 || read(fd, str, 1) != 0)
        return 0;
    return 1;
}

int create_map(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        dprintf(2, "le fichier %s n'a pas été trouvé ou n'a pas pu être ouvert\n", file);
        return 0;
    }
    if ((!fill_map(fd, file)) | (close(fd) == -1))
        return 0;
    return 1;
}
