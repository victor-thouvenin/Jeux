/*
** EPITECH PROJECT, 2018
** my_put_octal_str.c
** File description:
** print string
*/

#include <unistd.h>
#include "../print.h"

int my_put_octal_char(char c)
{
    my_putchar('\\');
    if (c < 8)
        my_putchar('0');
    if (c < 64)
        my_putchar('0');
    my_putunbr_base((int)c, "01234567");
    return 4;
}

int my_put_oct_str(va_list ap)
{
    int i = 0;
    char *str = va_arg(ap, char *);

    if (!str)
        return my_putstr("(null)");
    while (*str) {
        if (*str >= 32 && *str < 127)
            i += my_putchar(*str);
        else
            i += my_put_octal_char(*str);
        ++str;
    }
    return i;
}
