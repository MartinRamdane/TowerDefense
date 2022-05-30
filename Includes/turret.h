/*
** EPITECH PROJECT, 2022
** turret.h
** File description:
** turret.h
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <SFML/Config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef TURRET_H
#define TURRET_H
typedef struct turret
{
    int dmg;
    int speed;
    int target;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} trt;

typedef struct slot
{
    int is_place;
    int target;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} slot;

trt init_turret(char *file, int width, int height, int x, int y);
trt class_turret(trt turret, int target);
void move_turret_transparent(trt turret, sfWindow *window);
int target_analyse(int *target, sfWindow *window, int *money);
void draw_turret(trt turret, sfWindow *window);
slot init_slot(char *file, int width, int height, int x, int y);
void place_at_slot(int *target, slot *slot, sfRenderWindow *window, sfEvent event, int *money);
void display_slot(slot *slot, int *target, sfRenderWindow *window, sfEvent event, int *money);


#endif /* !TURRET_H */
