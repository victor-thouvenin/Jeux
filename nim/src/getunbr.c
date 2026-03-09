/*
** EPITECH PROJECT, 2018
** my_getunbr.c
** File description:
** atoui
*/

int getunbr(char const *str)
{
    unsigned int n = 0;

    if (*str == '+')
        str++;
    if (*str == '-')
        return -1;

    while (*str >= '0' && *str <= '9') {
        n = n * 10 + *str - '0';
        if ((n > 214748364 && str[1] != '\0') || (n == 214748364 && str[1] >= '8'))
            return -1;
        str++;
    }
    if (*str != '\0')
        return -1;
    return n;
}
