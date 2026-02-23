/*
** EPITECH PROJECT, 2018
** my_find_char.c
** File description:
** find char
*/

int my_find_char(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return i;
        ++i;
    }
    return -1;
}
