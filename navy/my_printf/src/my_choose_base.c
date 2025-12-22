/*
** EPITECH PROJECT, 2018
** my_choose_base
** File description:
** choose base
*/

#include "../print.h"

int put_b_base(va_list ap)
{
    return my_putunbr_base(va_arg(ap, unsigned int), "01");
}

int put_o_base(va_list ap)
{
    return my_putunbr_base(va_arg(ap, unsigned int), "01234567");
}

int put_x_base(va_list ap)
{
    return my_putunbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

int put_upx_base(va_list ap)
{
    return my_putunbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}
