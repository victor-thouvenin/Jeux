/*
** EPITECH PROJECT, 2018
** print_nbr
** File description:
** put nbr
*/

#include "../print.h"

int print_pos(unsigned int nb)
{
    int i = 0;

    if (nb > 9)
        i = print_pos(nb/10);
    printchar(nb%10 +48);
    return i+1;
}

int print_neg(int nb)
{
    int i = 1;

    printchar('-');
    if (nb < -9)
        i = print_pos(nb/-10);
    printchar(-1*(nb%10) +48);
    return i+1;
}

int print_nbr(va_list ap)
{
    int nb = va_arg(ap, int);

    if (nb < 0) {
        return print_neg(nb);
    }
    return print_pos((unsigned int)nb);
}

int print_unbr(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    return print_pos(nb);
}
