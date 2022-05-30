/*
** EPITECH PROJECT, 2022
** pause.c
** File description:
** pause.c
*/

#include "../Includes/my.h"

void display_pause(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("Pictures/pausemenu.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void pause_menu(int *is_pause, sfRenderWindow *window, sfEvent event)
{
    *is_pause = 1;
        display_pause(window);
        obj btn_return = init_object("Pictures/buttons/btn_returnmenu.png", 493, 76, 40, 850);
        returnmenu_btn(window, btn_return, 493, event);
}

void resumegame(sfRenderWindow *window, obj o_object, int offset, sfEvent event, int *is_click)
{
    sfSprite_setTexture(o_object.sprite, o_object.texture, sfTrue);
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    sfVector2f sprite_pos = sfSprite_getPosition(o_object.sprite);
    if (mouse_on_sprite(mouse_pos, sprite_pos,
    o_object.rect.width, o_object.rect.height) == 1) {
        o_object.rect.left = offset;
        if (event.type == sfEvtMouseButtonPressed && *is_click == 0) {
            *is_click = 1;
        }
    }
    sfSprite_setTextureRect(o_object.sprite, o_object.rect);
    sfSprite_setPosition(o_object.sprite, o_object.pos);
    sfRenderWindow_drawSprite(window, o_object.sprite, NULL);
}

void print_score(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfWhite);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

int pausemenu(sfRenderWindow *window, int score, int kichta)
{
    sfEvent event;
    int is_click = 0;
    obj bg = init_object("Pictures/pausemenu.png", 1920, 1080, 0, 0);
    obj btn_resume = init_object("Pictures/buttons/btn_resume.png", 600, 90, 675, 500);
    obj btn_backtomenu = init_object("Pictures/buttons/btn_backtomenu.png", 600, 90, 675, 650);
    obj btn_quit = init_object("Pictures/buttons/btn_exit.png", 600, 90, 675, 800);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
                is_click = 1;
            }
        }
        display_obj(window, bg);
        print_score(window, my_itoi(score), makepos(1000, 200), 50);
        print_score(window, my_itoi(kichta), makepos(1000, 270), 50);
        resumegame(window, btn_resume, 600, event, &is_click);
        returnmenu_btn(window, btn_backtomenu, 600, event);
        if (exit_btn(window, btn_quit, 600, event) == 1)
            return 2;
        if (is_click == 1)
            break;
        sfRenderWindow_display(window);
    }
    return 1;
}