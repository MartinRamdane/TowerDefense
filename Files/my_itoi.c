/*
** EPITECH PROJECT, 2021
** my_itoi.c
** File description:
** itoi
*/

#include "../Includes/my.h"

char *my_revstr(char *str)
{
    int i = 0, len = my_strlen(str) - 1;
    char tmp;
    while (i < len) {
        tmp = str[len];
        str[len] = str[i];
        str[i] = tmp;
        len = len - 1;
        i = i + 1;
    }
    return str;
}

int my_intlen(int nb)
{
    int i = 1;
    int k = 1;
    while (nb / k > 9) {
        i = i + 1;
        k = k * 10;
    }
    return i;
}

char *my_itoi(int nb)
{
    char *str = malloc(sizeof(char) * (my_intlen(nb) + 2));
    int i = 0, negatif = 0;
    if (nb < 0) {
        nb = nb * (- 1); negatif = 1;
    }
    if (nb == 0) {
        str[0] = '0'; return (str);
    }
    while (nb != 0) {
        int stock = nb % 10;
        if (stock > 9) {
            str[i] = (stock - 10) + 'a';
        } else {
            str[i] = stock + '0';
        }
        nb = nb / 10; i = i + 1;
    }
    if (negatif == 1)
        str[i] = '-';
    str = my_revstr(str); str[i] = '\0'; return (str);
}