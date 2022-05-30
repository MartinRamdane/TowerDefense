/*
** EPITECH PROJECT, 2022
** endgame.c
** File description:
** endgame.c
*/

#include "../Includes/my.h"

int endgame(sfRenderWindow *window, int score, int best_score)
{
    sfEvent event;
    obj bg = init_object("Pictures/lose_screen.png", 1920, 1080, 0, 0);
    obj btn_return = init_object("Pictures/buttons/btn_returnmenu.png", 493, 76, 750, 800);
    sfVector2f pos_text_score = {700, 400};
    sfVector2f pos_score = {1100, 400};
    sfVector2f pos_text_best_score = {700, 500};
    sfVector2f pos_best_score = {1100, 500};
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        display_obj(window, bg);
        returnmenu_btn(window, btn_return, 493, event);
        print_score(window, "Your score: " , pos_text_score, 50);
        print_score(window, my_itoi(score) , pos_score, 50);
        print_score(window, "Your best score: " , pos_text_best_score, 50);
        print_score(window, my_itoi(best_score) , pos_best_score, 50);
        sfRenderWindow_display(window);
    }
    return 1;
}