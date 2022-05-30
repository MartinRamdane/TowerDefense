/*
** EPITECH PROJECT, 2022
** btn_func.c
** File description:
** btn_func.c
*/

#include "../Includes/my.h"

void returnmenu_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (event.type == sfEvtMouseButtonPressed) {
            menu(window);
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
}

int play_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (event.type == sfEvtMouseButtonPressed) {
            game(window);
            return 1;
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
    return 0;
}

int exit_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (event.type == sfEvtMouseButtonPressed) {
            return 1;
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
    return 0;
}

void htp_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (event.type == sfEvtMouseButtonPressed) {
            htp(window);
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
}

int btn_turret(sfRenderWindow *window, obj o_object, int target, sfEvent event, int *money)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
        o_object.rect.width, o_object.rect.height) == 1) {
        if (event.type == sfEvtMouseButtonPressed) {
            return (target);
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
    if (mouse_on_sprite(mouse_pos, sprite_pos, o_object.rect.width, o_object.rect.height) == 1) {
        print_pop(mouse_pos, target, window, money);
    }
    return 0;
}
