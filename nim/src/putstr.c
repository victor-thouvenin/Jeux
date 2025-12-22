/*
** EPITECH PROJECT, 2018
** putstr.c
** File description:
** print string
*/

#include <unistd.h>
#include <string.h>

int putstr(char const *str)
{
    return write(1, str, strlen(str));
}

int puterror(char const *str)
{
    write(2, str, strlen(str));
    return 1;
}
