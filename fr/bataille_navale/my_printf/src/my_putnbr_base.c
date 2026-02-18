/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** ...
*/

#include "../print.h"

int putnbr_base(unsigned int nbr, unsigned int blen, char const *base)
{
    int i = 0;

    if (nbr >= blen)
        i = putnbr_base(nbr / blen, blen, base);
    my_putchar(base[nbr % blen]);
    ++i;
    return i;
}

int my_putunbr_base(unsigned int nbr, char const *base)
{
    unsigned int blen = 0;

    while (base[blen])
        blen++;
    return putnbr_base(nbr, blen, base);
}
