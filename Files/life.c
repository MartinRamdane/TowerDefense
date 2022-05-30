/*
** EPITECH PROJECT, 2022
** life.c
** File description:
** life.c
*/

#include "../Includes/my.h"

lifebar init_bar()
{
    lifebar barhealth;
    barhealth.bar_bg = sfTexture_createFromFile("Pictures/barhealth_background.png", NULL);
    barhealth.bar_life = sfTexture_createFromFile("Pictures/barhealth.png", NULL);
    barhealth.s_bar_bg = sfSprite_create();
    barhealth.s_bar_life = sfSprite_create();
    sfVector2f origin = {19, 19};
    sfVector2f positions = {1640, 826};
    barhealth.pos = positions;
    barhealth.rect.width = 250;
    barhealth.rect.height = 39;
    sfSprite_setTexture(barhealth.s_bar_bg, barhealth.bar_bg, sfTrue);
    sfSprite_setTexture(barhealth.s_bar_life, barhealth.bar_life, sfTrue);
    sfSprite_setTextureRect(barhealth.s_bar_life, barhealth.rect);
    sfSprite_setOrigin(barhealth.s_bar_bg, origin);
    sfSprite_setPosition(barhealth.s_bar_bg, barhealth.pos);
    sfSprite_setPosition(barhealth.s_bar_life, barhealth.pos);
    return (barhealth);
}


void display_life(int life, lifebar health, sfRenderWindow *window)
{
    health.rect.width = life;
    sfSprite_setTextureRect(health.s_bar_life, health.rect);
    sfRenderWindow_drawSprite(window, health.s_bar_bg, NULL);
    sfRenderWindow_drawSprite(window, health.s_bar_life, NULL);
}