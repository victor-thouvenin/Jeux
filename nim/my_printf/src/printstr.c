/*
** EPITECH PROJECT, 2018
** printstr.c
** File description:
** print string
*/

#include <string.h>
#include <unistd.h>
#include "../print.h"

int printstr(char *str)
{
    return write(1, str, strlen(str));
}

int vprintstr(va_list ap)
{
    char *str = va_arg(ap, char *);

    if (!str)
        return write(1, "(null)", 7);
    return write(1, str, strlen(str));
}
