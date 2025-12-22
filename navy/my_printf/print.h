/*
** EPITECH PROJECT, 2018
** print.h
** File description:
** header
*/

#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>

typedef struct flag_s {
    char flag;
    int(*func)(va_list);
} flag_t;

int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_putptr(va_list ap);
int my_putstr2(va_list ap);
int put_b_base(va_list ap);
int put_o_base(va_list ap);
int put_x_base(va_list ap);
int put_upx_base(va_list ap);
int my_put_nbr(va_list ap);
int my_put_unbr(va_list ap);
int my_putchar2(va_list ap);
int my_put_oct_str(va_list ap);
int my_printf(char const *str, ...);
int my_find_char(char const *str, char c);
int my_putunbr_base(unsigned int nbr, char const *base);

static const flag_t flags[] =
{{'s', &my_putstr2}, {'S', &my_put_oct_str}, {'p', &my_putptr},
{'c', &my_putchar2}, {'i', &my_put_nbr}, {'d', &my_put_nbr},
{'u', &my_put_unbr}, {'b', &put_b_base}, {'o', &put_o_base},
{'x', &put_x_base}, {'X', &put_upx_base}};

#endif
