/*
** EPITECH PROJECT, 2021
** functions.c
** File description:
** functions.c
*/

#include "../Includes/my.h"

int get_best_score()
{
    int fd = open("best_score.txt", O_RDONLY);
    char *score = malloc(sizeof(char) * 3);
    read(fd, score, 3);
    close(fd);
    return my_getnbr(score);
}

void new_best_score(int score)
{
    int fd = open("best_score.txt", O_WRONLY);
    write(fd, my_itoi(score), 3);
    close(fd);
}