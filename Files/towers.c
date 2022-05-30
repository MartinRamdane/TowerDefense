/*
** EPITECH PROJECT, 2022
** towers.c
** File description:
** towers.c
*/

#include "../Includes/turret.h"
#include "../Includes/my.h"

void tower_cible_mob(slot *slot, lcm *liste, sfClock *clock, soldats *my_soldats, unite *tank1, unite *tank2, unite *plane1, unite *plane2)
{
    if (slot -> is_place == 1) {
        int best_pos = 2000;
        int if_mob = 0;
        unite mob = liste -> mob;
        sfVector2f best_mob = {0, 0};
        while (liste != NULL) {
            while (liste -> mob.typeunit != slot -> target) {
                liste = liste -> next;
                if (liste == NULL)
                    break;
            }
            if (liste == NULL)
                break;
            if (((liste -> mob.sprite.pos.x >= slot -> pos.x - 260 && liste -> mob.sprite.pos.x <= slot -> pos.x + 260) &&
                (liste -> mob.sprite.pos.y >= slot -> pos.y - 215 && liste -> mob.sprite.pos.y <= slot -> pos.y + 215)) && liste -> mob.on_life == 1) {
                if_mob = 1;
                mob = liste -> mob;
                int calc_posx = (slot -> pos.x - liste -> mob.sprite.pos.x);
                int calc_posy = (slot -> pos.y - liste -> mob.sprite.pos.y);
                int calc_pos;
                if (calc_posx < 0)
                    calc_posx *= (-1);
                if (calc_posy < 0)
                    calc_posy *= (-1);
                calc_pos = calc_posx + calc_posy;
                if (calc_pos < best_pos) {
                    best_pos = calc_pos;
                    best_mob.x = liste -> mob.sprite.pos.x;
                    best_mob.y = liste -> mob.sprite.pos.y;
                }
            }
            liste = liste -> next;
        }
        if (if_mob == 1) {
            float dX = best_mob.x - slot -> pos.x;
            float dY = best_mob.y - slot -> pos.y;
            float fangle = (atan2(dY, dX) * 180) / 3.14159;
            sfSprite_setRotation(slot -> sprite, fangle + 90);
            if ((best_mob.x == my_soldats -> soldat1.sprite.pos.x && best_mob.y == my_soldats -> soldat1.sprite.pos.y) && my_soldats -> soldat1.on_life == 1)
                attack(clock, slot, &my_soldats -> soldat1);
            if ((best_mob.x == my_soldats -> soldat2.sprite.pos.x && best_mob.y == my_soldats -> soldat2.sprite.pos.y) && my_soldats -> soldat2.on_life == 1)
                attack(clock, slot, &my_soldats -> soldat2);
            if ((best_mob.x == my_soldats -> soldat3.sprite.pos.x && best_mob.y == my_soldats -> soldat3.sprite.pos.y) && my_soldats -> soldat3.on_life == 1)
                attack(clock, slot, &my_soldats -> soldat3);
            if ((best_mob.x == my_soldats -> soldat4.sprite.pos.x && best_mob.y == my_soldats -> soldat4.sprite.pos.y) && my_soldats -> soldat4.on_life == 1)
                attack(clock, slot, &my_soldats -> soldat4);
            if ((best_mob.x == tank1 -> sprite.pos.x && best_mob.y == tank1 -> sprite.pos.y) && tank1-> on_life == 1)
                attack(clock, slot, tank1);
            if ((best_mob.x == tank2 -> sprite.pos.x && best_mob.y == tank2 -> sprite.pos.y) && tank2 -> on_life == 1)
                attack(clock, slot, tank2);
            if ((best_mob.x == plane1 -> sprite.pos.x && best_mob.y == plane1 -> sprite.pos.y) && plane1 -> on_life == 1)
                attack(clock, slot, plane1);
            if ((best_mob.x == plane2 -> sprite.pos.x && best_mob.y == plane2 -> sprite.pos.y) && plane2 -> on_life == 1)
                attack(clock, slot, plane2);
        } else {
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
}