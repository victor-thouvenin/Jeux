/*
** EPITECH PROJECT, 2018
** my_getunbr.c
** File description:
** atoui
*/

int my_getunbr(char const *str)
{
    unsigned int n = 0;
    int s = 1;

    while (*str == '+' || *str == '-')
        s *= 44 - *str++;
    while (*str >= '0' && *str <= '9') {
        n = n * 10 + *str - '0';
        if (n > 429496729 && str[1] >= '6')
            return -1;
        str++;
    }
    if (s == -1 || (*str != '\0' && (*str < '0' || *str > '9')))
        return -1;
    return n;
}
