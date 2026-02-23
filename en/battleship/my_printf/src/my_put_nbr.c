/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put nbr
*/

#include "../print.h"

int put_pos(unsigned int nb)
{
    int i = 0;

    if (nb > 9)
        i = put_pos(nb / 10);
    my_putchar(nb % 10 + 48);
    ++i;
    return i;
}

int put_neg(int nb)
{
    int i = 1;

    my_putchar('-');
    if (nb < -9)
        i = put_pos(nb / -10);
    my_putchar(-1 * (nb % 10) + 48);
    ++i;
    return i;
}

int my_put_nbr(va_list ap)
{
    int nb = va_arg(ap, int);

    if (nb < 0) {
        return put_neg(nb);
    }
    return put_pos((unsigned int)nb);
}

int my_put_unbr(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    return put_pos(nb);
}
