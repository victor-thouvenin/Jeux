/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2) {
        if (*s1 == *s2) {
            ++s1;
            ++s2;
        }
        else
            break;
    }
    return (*s1 - *s2);
}
