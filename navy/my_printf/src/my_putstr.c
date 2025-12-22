/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** print string
*/

#include <unistd.h>
#include "../print.h"

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

int my_putstr2(va_list ap)
{
    char *str = va_arg(ap, char *);

    if (!str)
        return write(1, "(null)", 7);
    return write(1, str, my_strlen(str));
}
