/*
** EPITECH PROJECT, 2018
** printchar.c
** File description:
** putchar
*/

#include <unistd.h>
#include <stdarg.h>

int vprintchar(va_list ap)
{
    char c = va_arg(ap, int);

    return write(1, &c, 1);
}

int printchar(char c)
{
    return write(1, &c, 1);
}
