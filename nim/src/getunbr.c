/*
** EPITECH PROJECT, 2018
** my_getunbr.c
** File description:
** atoui
*/

int getunbr(char const *str)
{
    unsigned int n = 0;
    int s = 1;

    while (*str == '+' || *str == '-')
        s *= 44 - *str++;
    if (s == -1)
        return -1;
    while (*str >= '0' && *str <= '9') {
        n = n * 10 + *str - '0';
        if ((n > 214748364 && str[1]) || (n == 214748364 && str[1] >= '8'))
            return -1;
        str++;
    }
    if (*str != '\0')
        return -1;
    return n;
}
