/*
** EPITECH PROJECT, 2021
** print.c
** File description:
** print
*/

#include "../Includes/my.h"

void print_text_origin(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfVector2f origin = {my_strlen(str) / 2, 1};
    sfText_setOrigin(texte, origin);
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfBlack);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfBlack);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

sfVector2f makepos(int x, int y)
{
    sfVector2f pos = {x, y};
    return (pos);
}

void print_pop(sfVector2i mouse_pos, int target, sfRenderWindow *window, int *money)
{
    if (target == 1 && *money >= 200) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_land.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 100; sprite_pos.y = mouse_pos.y;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    } else if (target == 1 && *money < 200) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_nomoney.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 25; sprite_pos.y = mouse_pos.y + 150;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    }
    if (target == 2 && *money >= 250) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_tank.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 100; sprite_pos.y = mouse_pos.y;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    } else if (target == 2 && *money < 250) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_nomoney.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 25; sprite_pos.y = mouse_pos.y + 150;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    }
    if (target == 3 && *money >= 350) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_aerial.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 100; sprite_pos.y = mouse_pos.y;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    } else if (target == 3 && *money < 350) {
        sfTexture *texture = sfTexture_createFromFile("Pictures/popup_nomoney.png", NULL);
        sfSprite *popup = sfSprite_create();
        sfSprite_setTexture(popup, texture, sfTrue);
        sfSprite_setOrigin(popup, makepos(0, 120));
        sfVector2f sprite_pos; sprite_pos.x = mouse_pos.x + 25; sprite_pos.y = mouse_pos.y + 150;
        sfSprite_setPosition(popup, sprite_pos);
        sfRenderWindow_drawSprite(window, popup, NULL);
    }
}

void print_error_txt(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfRed);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

void print_sprite(sfRenderWindow *window, el element)
{
    sfSprite_setPosition(element.sprite, element.pos);
    sfSprite_setTexture(element.sprite, element.texture, sfTrue);
    sfSprite_setTextureRect(element.sprite, element.rect);
    sfRenderWindow_drawSprite(window, element.sprite, NULL);
}