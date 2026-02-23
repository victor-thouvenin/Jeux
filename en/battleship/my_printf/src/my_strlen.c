/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** str len
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (str)
        while (str[i])
            ++i;
    return i;
}
