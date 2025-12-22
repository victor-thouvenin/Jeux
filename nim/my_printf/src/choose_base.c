/*
** EPITECH PROJECT, 2018
** choose_base
** File description:
** choose base
*/

#include "../print.h"

int print_b_base(va_list ap)
{
    return print_unbr_base(va_arg(ap, unsigned int), "01");
}

int print_o_base(va_list ap)
{
    return print_unbr_base(va_arg(ap, unsigned int), "01234567");
}

int print_x_base(va_list ap)
{
    return print_unbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

int print_upx_base(va_list ap)
{
    return print_unbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}
