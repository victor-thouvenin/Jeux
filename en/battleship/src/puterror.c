/*
** EPITECH PROJECT, 2018
** my_puterror.c
** File description:
** print error msg
*/

#include <unistd.h>
#include "../my_printf/print.h"

int puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
