/*
** EPITECH PROJECT, 2018
** my_putptr
** File description:
** put ptr
*/

#include "../print.h"

unsigned long long putullnbr_base(unsigned long long nbr, char const *base)
{
    int i = 0;

    if (nbr > 16)
        i = putullnbr_base(nbr / 16, base);
    my_putchar(base[nbr % 16]);
    ++i;
    return i;
}

int my_putptr(va_list ap)
{
    void *ptr = va_arg(ap, void *);
    unsigned long long nbr = (unsigned long long)ptr;

    if (!ptr)
        return my_putstr("(nil)");
    my_putstr("0x");
    return (putullnbr_base(nbr, "0123456789abcdef") + 2);
}
