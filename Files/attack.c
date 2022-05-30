/*
** EPITECH PROJECT, 2022
** towers.c
** File description:
** towers.c
*/

#include "../Includes/turret.h"
#include "../Includes/my.h"

void up_score_and_money(int *score, int *moula, soldats *my_soldats, unite *tank1, unite *tank2, unite *plane1, unite *plane2)
{
    if (my_soldats -> soldat1.pv <= 0 && my_soldats -> soldat1.on_life == 1) {
        *score += 10;
        *moula += 150;
        my_soldats -> soldat1.pv = 50;
        my_soldats -> soldat1.sprite.pos.x = 250;
        my_soldats -> soldat1.sprite.pos.y = -100;
        int angle = 90 - my_soldats -> soldat1.sprite.angle;
        if (angle == 90)
            sfSprite_rotate(my_soldats -> soldat1.sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(my_soldats -> soldat1.sprite.sprite, 180);
        my_soldats -> soldat1.sprite.angle = 90;
    }
    if (my_soldats -> soldat2.pv <= 0 && my_soldats -> soldat2.on_life == 1) {
        *score += 10;
        *moula += 150;
        my_soldats -> soldat2.pv = 50;
        my_soldats -> soldat2.sprite.pos.x = 250;
        my_soldats -> soldat2.sprite.pos.y = -125;
        int angle = 90 - my_soldats -> soldat2.sprite.angle;
        if (angle == 90)
            sfSprite_rotate(my_soldats -> soldat2.sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(my_soldats -> soldat2.sprite.sprite, 180);
        my_soldats -> soldat2.sprite.angle = 90;
    }
    if (my_soldats -> soldat3.pv <= 0 && my_soldats -> soldat3.on_life == 1) {
        *score += 10;
        *moula += 150;
        my_soldats -> soldat3.pv = 50;
        my_soldats -> soldat3.sprite.pos.x = 250;
        my_soldats -> soldat3.sprite.pos.y = -150;
        int angle = 90 - my_soldats -> soldat3.sprite.angle;
        if (angle == 90)
            sfSprite_rotate(my_soldats -> soldat3.sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(my_soldats -> soldat3.sprite.sprite, 180);
        my_soldats -> soldat3.sprite.angle = 90;
    }
    if (my_soldats -> soldat4.pv <= 0 && my_soldats -> soldat4.on_life == 1) {
        *score += 10;
        *moula += 150;
        my_soldats -> soldat4.pv = 50;
        my_soldats -> soldat4.sprite.pos.x = 250;
        my_soldats -> soldat4.sprite.pos.y = -175;
        int angle = 90 - my_soldats -> soldat4.sprite.angle;
        if (angle == 90)
            sfSprite_rotate(my_soldats -> soldat4.sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(my_soldats -> soldat4.sprite.sprite, 180);
        my_soldats -> soldat4.sprite.angle = 90;
    }
    if (tank1 -> pv <= 0 && tank1 -> on_life == 1) {
        *score += 50;
        *moula += 250;
        tank1 -> pv = 200;
        tank1 -> sprite.pos.x = 250;
        tank1 -> sprite.pos.y = -400;
        int angle = 90 - tank1 -> sprite.angle;
        if (angle == 90)
            sfSprite_rotate(tank1 -> sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(tank1 ->sprite.sprite, 180);
    }
    if (tank2 -> pv <= 0 && tank2 -> on_life == 1) {
        *score += 50;
        *moula += 250;
        tank2 -> pv = 200;
        tank2 -> sprite.pos.x = 250;
        tank2 -> sprite.pos.y = -400;
        int angle = 90 - tank2 -> sprite.angle;
        if (angle == 90)
            sfSprite_rotate(tank2 -> sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(tank2 -> sprite.sprite, 180);
    }
    if (plane1 -> pv <= 0 && plane1 -> on_life == 1) {
        *score += 20;
        *moula += 100;
        plane1 -> pv = 25;
        plane1 -> sprite.pos.x = 250;
        plane1 -> sprite.pos.y = -2000;
        int angle = 90 - plane1 -> sprite.angle;
        if (angle == 90)
            sfSprite_rotate(plane1 -> sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(plane1 -> sprite.sprite, 180);
    }
    if (plane2 -> pv <= 0 && plane2 -> on_life == 1) {
        *score += 20;
        *moula += 100;
        plane2 -> pv = 25;
        plane2 -> sprite.pos.x = 250;
        plane2 -> sprite.pos.y = -2000;
        int angle = 90 - plane2 -> sprite.angle;
        if (angle == 90)
            sfSprite_rotate(plane2 -> sprite.sprite, 90);
        if (angle == 180)
            sfSprite_rotate(plane2 -> sprite.sprite, 180);
    }
}

void attack(sfClock *clock, slot *slot, unite *mob)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.7) {
        if (slot -> target == 1) {
            sfMusic *sound = sfMusic_createFromFile("Sounds/tank_shot.ogg");
            sfMusic_setVolume(sound, 30);
            sfMusic_play(sound);
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/attack_landturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
            mob -> pv -= 10;
        }
        if (slot -> target == 2) {
            sfMusic *sound = sfMusic_createFromFile("Sounds/tank_shot.ogg");
            sfMusic_setVolume(sound, 30);
            sfMusic_play(sound);
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/attack_tankturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
            mob -> pv -= 20;
        }
        if (slot -> target == 3) {
            sfMusic *sound = sfMusic_createFromFile("Sounds/rocket.ogg");
            sfMusic_setVolume(sound, 30);
            sfMusic_play(sound);
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/attack_planeturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
            mob -> pv -= 5;
        }
        sfClock_restart(clock);
    } else if (seconds > 0.1){
        if (slot -> target == 1) {
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/landturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
        }
        if (slot -> target == 2) {
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/tankturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
        }
        if (slot -> target == 3) {
            slot -> texture = sfTexture_createFromFile("Pictures/turrets/planeturret.png", NULL);
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
        }
    }
}