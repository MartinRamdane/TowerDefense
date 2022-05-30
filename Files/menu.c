/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu.c
*/

#include "../Includes/my.h"

int menu(sfRenderWindow *window)
{
    sfEvent event;
    obj bg = init_object("Pictures/menu_bg.png", 1920, 1080, 0, 0);
    obj btn_play = init_object("Pictures/buttons/btn_play.png", 600, 90, 650, 400);
    obj btn_htp = init_object("Pictures/buttons/btn_htp.png", 600, 90, 650, 600);
    obj btn_quit = init_object("Pictures/buttons/btn_exit.png", 600, 90, 650, 800);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        display_obj(window, bg);
        int play = play_btn(window, btn_play, 600, event);
        if (play == 1)
            return 1;
        htp_btn(window, btn_htp, 600, event);
        if (exit_btn(window, btn_quit, 600, event) == 1)
            return 1;
        sfRenderWindow_display(window);
    }
    return 1;
}