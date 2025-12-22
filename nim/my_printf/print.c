/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <unistd.h>
#include "print.h"

int find_char(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return i;
        ++i;
    }
    return -1;
}

int my_printf(char const *str, ...)
{
    if (!str)
        return -1;

    va_list ap;
    va_start(ap, str);

    int nb = 0;
    int i = 0;
    while (*str) {
        if (*str == '%' && str[1] == '%') {
            nb += printchar('%');
            ++str;
        } if (*str == '%' && (i = find_char(FLAGS, str[1])) != -1) {
            nb += flags[i].func(ap);
            ++str;
        } else
            nb += write(1, str, 1);
        ++str;
    }
    va_end(ap);
    return nb;
}
