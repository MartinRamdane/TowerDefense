/*
** EPITECH PROJECT, 2022
** htp.c
** File description:
** htp.c
*/

#include "../Includes/my.h"

int htp(sfRenderWindow *window)
{
    sfEvent event;
    obj bg = init_object("Pictures/htp_bg.png", 1920, 1080, 0, 0);
    obj btn_return = init_object("Pictures/buttons/btn_returnmenu.png", 493, 76, 40, 850);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        display_obj(window, bg);
        returnmenu_btn(window, btn_return, 493, event);
        sfRenderWindow_display(window);
    }
    return 1;
}