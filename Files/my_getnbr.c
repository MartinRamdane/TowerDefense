/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** getnbr
*/

int my_getnbr(char *str)
{
    int i = 0, result = 0;
    while (str[i]) {
        result = result * 10;
        result = result + str[i] - 48;
        i = i + 1;
    }
    return result;
}