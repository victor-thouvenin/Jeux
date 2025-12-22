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

int my_printf(char const *str, ...);

int printchar(char c);
int printstr(char *str);
int print_unbr_base(unsigned int nbr, char const *base);

int vprintchar(va_list ap);
int vprintstr(va_list ap);
int print_oct_str(va_list ap);
int printptr(va_list ap);
int print_nbr(va_list ap);
int print_unbr(va_list ap);
int print_b_base(va_list ap);
int print_o_base(va_list ap);
int print_x_base(va_list ap);
int print_upx_base(va_list ap);

#define FLAGS "sSpciduboxX"
static const flag_t flags[] =
{{'s', &vprintstr}, {'S', &print_oct_str}, {'p', &printptr},
{'c', &vprintchar}, {'i', &print_nbr}, {'d', &print_nbr},
{'u', &print_unbr}, {'b', &print_b_base}, {'o', &print_o_base},
{'x', &print_x_base}, {'X', &print_upx_base}};

#endif
