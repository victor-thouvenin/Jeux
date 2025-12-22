/*
** EPITECH PROJECT, 2018
** print_nbr_base.c
** File description:
** ...
*/

#include "../print.h"

int print_nbr_base(unsigned int nbr, unsigned int blen, char const *base)
{
    int i = 0;

    if (nbr >= blen)
        i = print_nbr_base(nbr / blen, blen, base);
    printchar(base[nbr % blen]);
    return i+1;
}

int print_unbr_base(unsigned int nbr, char const *base)
{
    unsigned int blen = 0;

    while (base[blen])
        blen++;
    return print_nbr_base(nbr, blen, base);
}
