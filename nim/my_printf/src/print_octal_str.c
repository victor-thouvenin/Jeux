/*
** EPITECH PROJECT, 2018
** print_octal_str.c
** File description:
** print string
*/

#include <unistd.h>
#include "../print.h"

int print_octal_char(char c)
{
    printchar('\\');
    if (c < 8)
        printchar('0');
    if (c < 64)
        printchar('0');
    print_unbr_base((int)c, "01234567");
    return 4;
}

int print_oct_str(va_list ap)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    if (!str)
        return printstr("(null)");
    while (*str) {
        if (*str >= 32 && *str < 127)
            i += printchar(*str);
        else
            i += print_octal_char(*str);
        ++str;
    }
    return i;
}
