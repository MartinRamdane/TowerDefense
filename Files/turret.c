/*
** EPITECH PROJECT, 2022
** turret.c
** File description:
** turret.c
*/

#include "../Includes/turret.h"

trt init_turret(char *file, int width, int height, int x, int y)
{
    trt o_turret;
    o_turret.dmg = 0;
    o_turret.speed = 0;
    o_turret.target = 0;
    o_turret.texture = sfTexture_createFromFile(file, NULL);
    o_turret.sprite = sfSprite_create();
    o_turret.pos.x = x;
    o_turret.pos.y = y;
    sfSprite_setPosition(o_turret.sprite, o_turret.pos);
    o_turret.rect.width = width;
    o_turret.rect.height = height;
    o_turret.rect.left = 0;
    o_turret.rect.top = 0;
    sfSprite_setTextureRect(o_turret.sprite, o_turret.rect);
    return (o_turret);
}

trt class_turret(trt turret, int target)
{
    if (target == 1) {
        turret.dmg = 50;
        turret.speed = 10;
        turret.target = target;
    } else if (target == 2) {
        turret.dmg = 100;
        turret.speed = 5;
        turret.target = target;
    } else if (target == 3) {
        turret.dmg = 75;
        turret.speed =  7;
        turret.target = target;
    }
    return (turret);
}

void draw_turret(trt turret, sfWindow *window)
{
    sfSprite_setTexture(turret.sprite, turret.texture, sfTrue);
    sfSprite_setTextureRect(turret.sprite, turret.rect);
    sfSprite_setPosition(turret.sprite, turret.pos);
    sfRenderWindow_drawSprite(window, turret.sprite, NULL);
}

void move_turret_transparent(trt turret, sfWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    turret.pos.x = mouse_pos.x;
    turret.pos.y = mouse_pos.y;
    sfVector2f turret_origin = {68, 68};
    sfSprite_setOrigin(turret.sprite, turret_origin);
    draw_turret(turret, window);
}

int target_analyse(int *target, sfWindow *window, int *money)
{
    if (*target == 1 && *money >= 200) {
        sfVector2i mouse_pos = sfMouse_getPosition(window);
        trt turret = init_turret("Pictures/turrets/landturret.png", 128, 128, mouse_pos.x, mouse_pos.y);
        sfColor color_turret = sfSprite_getColor(turret.sprite);
        color_turret.a = 200;
        sfSprite_setColor(turret.sprite, color_turret);
        turret = class_turret(turret, 1);
        move_turret_transparent(turret, window);
    }else if (*target == 2 && *money >= 250) {
        sfVector2i mouse_pos = sfMouse_getPosition(window);
        trt turret = init_turret("Pictures/turrets/tankturret.png", 128, 128, mouse_pos.x, mouse_pos.y);
        sfColor color_turret = sfSprite_getColor(turret.sprite);
        color_turret.a = 200;
        sfSprite_setColor(turret.sprite, color_turret);
        turret = class_turret(turret, 2);
        move_turret_transparent(turret, window);
    } else if (*target == 3 && *money >= 350) {
        sfVector2i mouse_pos = sfMouse_getPosition(window);
        trt turret = init_turret("Pictures/turrets/planeturret.png", 128, 128, mouse_pos.x, mouse_pos.y);
        sfColor color_turret = sfSprite_getColor(turret.sprite);
        color_turret.a = 200;
        sfSprite_setColor(turret.sprite, color_turret);
        turret = class_turret(turret, 3);
        move_turret_transparent(turret, window);
    } else {
        *target = 0;
    }
    return 0;
}