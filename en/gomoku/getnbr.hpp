/*
** EPITECH PROJECT, 2018
** getnbr.hpp
** File description:
** getnbr
*/

#pragma once

#include <exception>
#include <stdexcept>
#include <cmath>
#include <limits>

template<typename T>
T getnbr(char const *str)
{
    int s = 1;
    T n = 0;
    T d = 0;
    T pow10 = 1;
    T max = std::numeric_limits<T>::max();
    T min = std::numeric_limits<T>::min();
    T low = std::numeric_limits<T>::lowest();

    if (*str == '+' || *str == '-') {
        if (*str == '-')
            s = -1;
        ++str;
    }
    if (s < 0 && low >= 0)
        throw std::out_of_range("out of range");
    while (*str >= '0' && *str <= '9') {
        if (n > max/10 || (n == max/10 && *str > fmod(max,10.0) + '0') ||
            n < low/10 || (n == low/10 && *str > fmod(low,10.0) + '0'))
            throw std::out_of_range("out of range");
        n = n*10 + (*str-'0')*s;
        ++str;
    }
    if (*str == '.' && min < 1 && min > 0) {
        ++str;
        while (*str >= '0' && *str <= '9') {
            if (d != 0 && d < min)
                throw std::out_of_range("out of range");
            pow10 /= 10;
            d += (*str-'0')*pow10;
            ++str;
        }
    }
    if (*str != '\0')
        throw std::invalid_argument("is not a number");
    n += s*d;
    return n;
}
