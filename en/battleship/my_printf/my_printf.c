/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <unistd.h>
#include "print.h"

int print(va_list ap, char const *str)
{
    int i = 0;

    while (i < 11 && *str != flags[i].flag)
        ++i;
    if (i < 11)
        return (flags[i].func(ap));
    else
        return my_putchar('%');
    return 0;
}

int my_printf(char const *str, ...)
{
    int i = 0;
    va_list ap;

    if (!str)
        return -1;
    va_start(ap, str);
    while (*str) {
        if (*str == '%' && my_find_char("sSpciduboxX%", str[1]) != -1)
            i += print(ap, ++str);
        else
            i += write(1, str, 1);
        ++str;
    }
    va_end(ap);
    return i;
}
