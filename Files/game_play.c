/*
** EPITECH PROJECT, 2021
** game_play.c
** File description:
** runner
*/

#include "../Includes/my.h"
#include "../Includes/turret.h"


void game(sfRenderWindow *window)
{
    sfEvent event;
    int is_pause = 0;
    int life = 250;
    int score = 0;
    int money = 650;
    int best_score = get_best_score();
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    soldats my_soldats = init_soldats(50, 5);
    sfVector2f pos_tank1 = {250, -400};
    sfVector2f pos_tank2 = {250, -600};
    sfVector2f pos_plane1 = {250, -2000};
    sfVector2f pos_plane2 = {250, -4000};
    sfVector2f pos_money = {1735, 1002};
    sfVector2f pos_score = {1747, 912};
    unite my_plane1 = init_plane(45, 7, "Pictures/mobs/avion1.png", pos_plane1);
    unite my_plane2 = init_plane(45, 7, "Pictures/mobs/avion2.png", pos_plane2);
    unite my_tank1 = init_tank(200, 3, "Pictures/mobs/tank1.png", pos_tank1);
    unite my_tank2 = init_tank(200, 3, "Pictures/mobs/tank2.png", pos_tank2);
    int target = 0;
    sfMusic *sound = play_sound("sounds/musictheme.ogg", 30);
    obj turret_l = init_object("Pictures/turrets/landturret.png", 128, 128, 155, 840);
    obj turret_t = init_object("Pictures/turrets/tankturret.png", 128, 128,  680, 840);
    obj turret_a = init_object("Pictures/turrets/planeturret.png", 128, 128, 1205, 840);
    slot slot1 = init_slot("Pictures/turrets/slot.png", 128, 128, 18 + 64, 262 + 64);
    slot slot2 = init_slot("Pictures/turrets/slot.png", 128, 128, 18 + 64, 402 + 64);
    slot slot3 = init_slot("Pictures/turrets/slot.png", 128, 128, 18 + 64, 542 + 64);
    slot slot4 = init_slot("Pictures/turrets/slot.png", 128, 128, 368 + 64, 402 + 64);
    slot slot5 = init_slot("Pictures/turrets/slot.png", 128, 128, 508 + 64, 402 + 64);
    slot slot6 = init_slot("Pictures/turrets/slot.png", 128, 128, 648 + 64, 402 + 64);
    slot slot7 = init_slot("Pictures/turrets/slot.png", 128, 128, 368 + 64, 122 + 64);
    slot slot8 = init_slot("Pictures/turrets/slot.png", 128, 128, 648 + 64, 122 + 64);
    slot slot9 = init_slot("Pictures/turrets/slot.png", 128, 128, 1008 + 64, 542 + 64);
    slot slot10 = init_slot("Pictures/turrets/slot.png", 128, 128, 1008 + 64, 262 + 64);
    slot slot11 = init_slot("Pictures/turrets/slot.png", 128, 128, 1168 + 64, 262 + 64);
    slot slot12 = init_slot("Pictures/turrets/slot.png", 128, 128, 1168 + 64, 542 + 64);
    slot slot13 = init_slot("Pictures/turrets/slot.png", 128, 128, 1668 + 64, 402 + 64);
    slot slot14 = init_slot("Pictures/turrets/slot.png", 128, 128, 1528 + 64, 262 + 64);
    slot slot15 = init_slot("Pictures/turrets/slot.png", 128, 128, 1528 + 64, 402 + 64);
    lcm *liste = init_liste_chainee_mobs(my_soldats, my_tank1, my_tank2, my_plane1, my_plane2);
    lifebar health = init_bar();
    c clocks = init_clocks();
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && is_pause == 0) {
                sfMusic_pause(sound);
                if (pausemenu(window, score, money) == 2)
                    return;
                sfMusic_play(sound);
            }
            if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue && target != 0)
                target = 0;
        }
        print_sprite(window, map);
        if (my_plane1.on_life == 1) print_sprite(window, my_plane1.sprite);
        if (my_plane2.on_life == 1) print_sprite(window, my_plane2.sprite);
        if (my_soldats.soldat1.on_life == 1) print_sprite(window, my_soldats.soldat1.sprite);
        if (my_soldats.soldat2.on_life == 1) print_sprite(window, my_soldats.soldat2.sprite);
        if (my_soldats.soldat3.on_life == 1) print_sprite(window, my_soldats.soldat3.sprite);
        if (my_soldats.soldat4.on_life == 1) print_sprite(window, my_soldats.soldat4.sprite);
        if (my_tank1.on_life == 1) print_sprite(window, my_tank1.sprite);
        if (my_tank2.on_life == 1) print_sprite(window, my_tank2.sprite);
        print_text_origin(window, my_itoi(money), pos_money, 35);
        print_text_origin(window, my_itoi(score), pos_score, 35);
        if (my_soldats.soldat1.on_life == 1) rotate_soldat(&my_soldats.soldat1.sprite);
        if (my_soldats.soldat2.on_life == 1) rotate_soldat(&my_soldats.soldat2.sprite);
        if (my_soldats.soldat3.on_life == 1) rotate_soldat(&my_soldats.soldat3.sprite);
        if (my_soldats.soldat4.on_life == 1) rotate_soldat(&my_soldats.soldat4.sprite);
        if (my_plane1.on_life == 1) rotate_plane(&my_plane1.sprite);
        if (my_plane2.on_life == 1) rotate_plane(&my_plane2.sprite);
        if (my_tank1.on_life == 1) rotate_tank(&my_tank1.sprite);
        if (my_tank2.on_life == 1) rotate_tank(&my_tank2.sprite);
        if (my_soldats.soldat1.on_life == 1) move_soldat(&my_soldats.soldat1, my_soldats.soldat1.speed, clocks.clock1, &life, my_soldats.soldat1.dammage);
        if (my_soldats.soldat2.on_life == 1) move_soldat(&my_soldats.soldat2, my_soldats.soldat2.speed, clocks.clock2, &life, my_soldats.soldat2.dammage);
        if (my_soldats.soldat3.on_life == 1 )move_soldat(&my_soldats.soldat3, my_soldats.soldat3.speed, clocks.clock3, &life, my_soldats.soldat3.dammage);
        if (my_soldats.soldat4.on_life == 1) move_soldat(&my_soldats.soldat4, my_soldats.soldat4.speed, clocks.clock4, &life, my_soldats.soldat4.dammage);
        if (my_tank1.on_life == 1) move_tank(&my_tank1, my_tank1.speed, clocks.clock5, &life, my_tank1.dammage);
        if (my_tank2.on_life == 1) move_tank(&my_tank2, my_tank2.speed, clocks.clock6, &life, my_tank2.dammage);
        if (my_plane1.on_life == 1) move_plane(&my_plane1, my_plane1.speed, clocks.clock7, &life, my_plane1.dammage);
        if (my_plane2.on_life == 1) move_plane(&my_plane2, my_plane2.speed, clocks.clock8, &life, my_plane1.dammage);
        liste = init_liste_chainee_mobs(my_soldats, my_tank1, my_tank2, my_plane1, my_plane2);
        if (target == 0)
            target = btn_turret(window, turret_l, 1, event, &money);
        if (target == 0)
            target = btn_turret(window, turret_t, 2, event, &money);
        if (target == 0)
            target = btn_turret(window, turret_a, 3, event, &money);
        display_slot(&slot1, &target, window, event, &money);
        display_slot(&slot2, &target, window, event, &money);
        display_slot(&slot3, &target, window, event, &money);
        display_slot(&slot4, &target, window, event, &money);
        display_slot(&slot5, &target, window, event, &money);
        display_slot(&slot6, &target, window, event, &money);
        display_slot(&slot7, &target, window, event, &money);
        display_slot(&slot8, &target, window, event, &money);
        display_slot(&slot9, &target, window, event, &money);
        display_slot(&slot10, &target, window, event, &money);
        display_slot(&slot11, &target, window, event, &money);
        display_slot(&slot12, &target, window, event, &money);
        display_slot(&slot13, &target, window, event, &money);
        display_slot(&slot14, &target, window, event, &money);
        display_slot(&slot15, &target, window, event, &money);
        target_analyse(&target, window, &money);
        tower_cible_mob(&slot1, liste, clocks.clock9, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot2, liste, clocks.clock10, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot3, liste, clocks.clock11, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot4, liste, clocks.clock12, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot5, liste, clocks.clock13, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot6, liste, clocks.clock14, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot7, liste, clocks.clock15, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot8, liste, clocks.clock16, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot9, liste, clocks.clock17, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot10, liste, clocks.clock18, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot11, liste, clocks.clock19, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot12, liste, clocks.clock20, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot13, liste, clocks.clock21, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot14, liste, clocks.clock22, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        tower_cible_mob(&slot15, liste, clocks.clock23, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        up_score_and_money(&score, &money, &my_soldats, &my_tank1, &my_tank2, &my_plane1, &my_plane2);
        if (life <= 0) {
            if (score > best_score) {
                new_best_score(score);
                best_score = score;
            }
            sfMusic_stop(sound);
            sfMusic_destroy(sound);
            endgame(window, score, best_score);
        }
        display_life(life, health, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My defender", sfResize | sfClose, NULL);
    menu(window);
}