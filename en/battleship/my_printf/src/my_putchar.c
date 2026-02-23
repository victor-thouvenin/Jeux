/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** putchar
*/

#include <unistd.h>
#include <stdarg.h>

int my_putchar2(va_list ap)
{
    char c = va_arg(ap, int);

    write(1, &c, 1);
    return 1;
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
