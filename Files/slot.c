/*
** EPITECH PROJECT, 2022
** slot.c
** File description:
** slot.c
*/

#include "../Includes/turret.h"
#include "../Includes/my.h"

int mouse_on_slot(sfVector2i mouse_pos, sfVector2f sprite_pos, int width, int height)
{
    if (mouse_pos.x >= sprite_pos.x - 64 && mouse_pos.x <= (sprite_pos.x + width - 64)
        && mouse_pos.y >= sprite_pos.y - 64 && mouse_pos.y <= (sprite_pos.y + height - 64)) {
            return 1;
    } else {
        return 0;
    }
}

slot init_slot(char *file, int width, int height, int x, int y)
{
    slot o_slot;
    o_slot.texture = sfTexture_createFromFile(file, NULL);
    o_slot.sprite = sfSprite_create();
    o_slot.pos.x = x;
    o_slot.pos.y = y;
    o_slot.rect.width = width;
    o_slot.rect.height = height;
    sfVector2f origin = {64, 64};
    sfSprite_setOrigin(o_slot.sprite, origin);
    o_slot.rect.left = 0;
    o_slot.rect.top = 0;
    o_slot.is_place = 0;
    return(o_slot);
}

void display_slot(slot *slot, int *target, sfRenderWindow *window, sfEvent event, int *money)
{
    if (*target != 0)
        place_at_slot(target, slot, window, event, money);
    sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
    sfSprite_setTextureRect(slot -> sprite, slot -> rect);
    sfSprite_setPosition(slot -> sprite, slot -> pos);
    sfRenderWindow_drawSprite(window, slot -> sprite, NULL);
}

void place_at_slot(int *target, slot *slot, sfRenderWindow *window, sfEvent event, int *money)
{
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    if (mouse_on_slot(mouse_pos, slot -> pos,
    slot -> rect.width, slot -> rect.height) == 1) {
        if (event.type == sfEvtMouseButtonPressed && slot -> is_place == 0) {
            if (*target == 1) {
                slot -> texture = sfTexture_createFromFile("Pictures/turrets/landturret.png", NULL);
                slot -> target = 1;
                *target = 0;
                *money = *money - 200;
                slot -> is_place = 1;
            } else if (*target == 2) {
                slot -> texture = sfTexture_createFromFile("Pictures/turrets/tankturret.png", NULL);
                slot -> target = 2;
                *target = 0;
                *money -= 250;
                slot -> is_place = 1;
            } else if (*target == 3) {
                slot -> texture = sfTexture_createFromFile("Pictures/turrets/planeturret.png", NULL);
                slot -> target = 3;
                *target = 0;
                *money -= 350;
                slot -> is_place = 1;
            } else {
                *target = 0;
                return;
            }
            sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
            sfSprite_setTextureRect(slot -> sprite, slot -> rect);
            display_slot(slot, target, window, event, money);
        }
    }
}