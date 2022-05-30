/*
** EPITECH PROJECT, 2021
** move_element.c
** File description:
** move an element
*/

#include "../Includes/my.h"

void move_plane(unite *element, int offset, sfClock *clock, int *life, int dammage)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        if (element -> sprite.pos.x == 250 && element -> sprite.pos.y <= 650)
            element -> sprite.pos.y += offset;
        if (element -> sprite.pos.x <= 900 && element -> sprite.pos.y >= 650)
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.x == 901 && element -> sprite.pos.y >= 150)
            element -> sprite.pos.y -= offset;
        if ((element -> sprite.pos.y == 149 || element -> sprite.pos.y == 144) && (element -> sprite.pos.x >= 900 && element -> sprite.pos.x <= 1405))
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.y <= 640 && element -> sprite.pos.x == 1405)
            element -> sprite.pos.y += offset;
        if ((element -> sprite.pos.y == 641 || element -> sprite.pos.y == 646) && element -> sprite.pos.x >= 1405)
            element -> sprite.pos.x += offset;
        if ((element -> sprite.pos.y == 641 || element -> sprite.pos.y == 646) && element -> sprite.pos.x >= 2000) {
            element -> sprite.pos.x = 250;
            element -> sprite.pos.y = -2000;
            element -> pv = 5;
            *life -= dammage;
        }
        sfClock_restart(clock);
    }
}

void rotate_plane(el *element)
{
    if (element -> pos.x == 250 && (element -> pos.y == 646 || element -> pos.y == 648)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if (element -> pos.x == 901 && (element -> pos.y == 646 || element -> pos.y == 648)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = - 90;
    }
    if (element -> pos.x == 901 && (element -> pos.y == 151 || element -> pos.y == 156)) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 0;
    }
    if (element -> pos.x == 1405 && (element -> pos.y == 151 || element -> pos.y == 156)) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
    if ((element -> pos.y == 639 || element -> pos.y == 641) && (element -> pos.x == 1412 || element -> pos.x == 1405)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if ((element -> pos.y == 641 || element -> pos.y == 646) && element -> pos.x == 1993) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
}

void move_soldat(unite *element, int offset, sfClock *clock, int *life, int dammage)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        if (element -> sprite.pos.x == 250 && element -> sprite.pos.y <= 650)
            element -> sprite.pos.y += offset;
        if (element -> sprite.pos.x <= 900 && element -> sprite.pos.y >= 650)
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.x == 900 && element -> sprite.pos.y >= 150)
            element -> sprite.pos.y -= offset;
        if (element -> sprite.pos.y == 150 && (element -> sprite.pos.x >= 900 && element -> sprite.pos.x <= 1405))
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.y <= 640 && element -> sprite.pos.x == 1405)
            element -> sprite.pos.y += offset;
        if (element -> sprite.pos.y == 645 && element -> sprite.pos.x >= 1405)
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.y == 645 && element -> sprite.pos.x == 2000) {
            element -> sprite.pos.x = 250;
            element -> sprite.pos.y = -100;
            element -> pv = 50;
            *life -= dammage;
        }
        sfClock_restart(clock);
    }
}

void move_tank(unite *element, int offset, sfClock *clock, int *life, int dammage)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        if (element -> sprite.pos.x == 250 && element -> sprite.pos.y <= 650)
            element -> sprite.pos.y += offset;
        if (element -> sprite.pos.x <= 900 && element -> sprite.pos.y >= 650)
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.x == 901 && element -> sprite.pos.y >= 150)
            element -> sprite.pos.y -= offset;
        if ((element -> sprite.pos.y == 150 || element -> sprite.pos.y == 149) && (element -> sprite.pos.x >= 900 && element -> sprite.pos.x <= 1405))
            element -> sprite.pos.x += offset;
        if (element -> sprite.pos.y <= 640 && element -> sprite.pos.x == 1405)
            element -> sprite.pos.y += offset;
        if ((element -> sprite.pos.y == 641 || element -> sprite.pos.y == 642) && element -> sprite.pos.x >= 1405)
            element -> sprite.pos.x += offset;
        if ((element -> sprite.pos.y == 641 || element -> sprite.pos.y == 642) && element -> sprite.pos.x >= 2000) {
            element -> sprite.pos.x = 250;
            element -> sprite.pos.y = -400;
            *life -= dammage;
            element -> pv = 200;
        }
        sfClock_restart(clock);
    }
}

void rotate_tank(el *element)
{
    if (element -> pos.x == 250 && (element -> pos.y >= 647 && element -> pos.y <= 649)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if ((element -> pos.x >= 897 && element -> pos.x <= 900) && (element -> pos.y == 650 || element -> pos.y == 651)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = -90;
    }
    if ((element -> pos.x >= 900 && element -> pos.x <= 904) && (element -> pos.y == 149 || element -> pos.y == 150)) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 0;
    }
    if ((element -> pos.x >= 1400 && element -> pos.x <= 1405) && (element -> pos.y == 149 || element -> pos.y == 150)) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
    if ((element -> pos.y >= 637 && element -> pos.y <= 640) && element -> pos.x == 1405) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if ((element -> pos.y == 641 || element -> pos.y == 642) && (element -> pos.x >= 1997 && element -> pos.x <= 2000)) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
}

void rotate_soldat(el *element)
{
    if (element -> pos.x == 250 && element -> pos.y == 640) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if (element -> pos.x == 900 && element -> pos.y == 645) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = -90;
    }
    if (element -> pos.x == 900 && element -> pos.y == 155) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 0;
    }
    if (element -> pos.x == 1400 && element -> pos.y == 150) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
    if (element -> pos.y == 640 && (element -> pos.x >= 1400 && element -> pos.x < 1990)) {
        sfSprite_rotate(element -> sprite, 270);
        element -> angle = 0;
    }
    if (element -> pos.y == 645 && element -> pos.x == 1995) {
        sfSprite_rotate(element -> sprite, -270);
        element -> angle = 90;
    }
}
