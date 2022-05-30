/*
** EPITECH PROJECT, 2021
** functions.c
** File description:
** functions.c
*/

#include "../Includes/my.h"

obj init_object(char *file, int width, int height, int x, int y)
{
    obj o_object;
    o_object.texture = sfTexture_createFromFile(file, NULL);
    o_object.sprite = sfSprite_create();
    o_object.pos.x = x;
    o_object.pos.y = y;
    o_object.rect.width = width;
    o_object.rect.height = height;
    o_object.rect.left = 0;
    o_object.rect.top = 0;
    return (o_object);
}

void display_obj(sfRenderWindow *window, obj o_object)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
}

void display_btn(sfRenderWindow *window, obj o_object, int offset, int value, sfEvent event)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (value == 2 && event.type == sfEvtMouseButtonPressed)
            //settings(window);
        if (value == 3 && event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(window);
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
}

int mouse_on_sprite(sfVector2i mouse_pos, sfVector2f sprite_pos, int width, int height)
{
    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= (sprite_pos.x + width)
        && mouse_pos.y >= sprite_pos.y && mouse_pos.y <= (sprite_pos.y + height)) {
            return 1;
    } else {
        return 0;
    }
}

sfMusic *play_sound(char *filepath, int vol)
{
    sfMusic *sound = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(sound, sfTrue);
    sfMusic_setVolume(sound, vol);
    sfMusic_play(sound);
    return (sound);
}