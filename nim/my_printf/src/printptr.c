/*
** EPITECH PROJECT, 2018
** printptr
** File description:
** print ptr
*/

#include "../print.h"

unsigned long long putullnbr_base(unsigned long long nbr, char const *base)
{
    int i = 0;

    if (nbr > 16)
        i = putullnbr_base(nbr / 16, base);
    printchar(base[nbr % 16]);
    return i+1;
}

int printptr(va_list ap)
{
    void *ptr = va_arg(ap, void *);
    unsigned long long nbr = (unsigned long long)ptr;

    if (!ptr)
        return printstr("(nil)");
    printstr("0x");
    return (putullnbr_base(nbr, "0123456789abcdef") + 2);
}
