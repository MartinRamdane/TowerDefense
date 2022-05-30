/*
** EPITECH PROJECT, 2021
** framebuffer.h
** File description:
** framebuffer
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <SFML/Config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "turret.h"
#include <math.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef struct clock {
    sfClock *clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
    sfClock *clock5;
    sfClock *clock6;
    sfClock *clock7;
    sfClock *clock8;
    sfClock *clock9;
    sfClock *clock10;
    sfClock *clock11;
    sfClock *clock12;
    sfClock *clock13;
    sfClock *clock14;
    sfClock *clock15;
    sfClock *clock16;
    sfClock *clock17;
    sfClock *clock18;
    sfClock *clock19;
    sfClock *clock20;
    sfClock *clock21;
    sfClock *clock22;
    sfClock *clock23;
} c;

typedef struct element_game {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    int angle;
} el;

typedef struct unite {
    el sprite;
    int typeunit;
    int pv;
    int speed;
    int dammage;
    int dammage_muerte;
    int on_life;
} unite;

typedef struct soldat {
    el sprite;
    int pv;
    int speed;
    int dammage;
    int dammage_muerte;
} soldat;

typedef struct tank {
    el sprite;
    int pv;
    int speed;
    int dammage;
    int dammage_muerte;
} tank;

typedef struct plane {
    el sprite;
    int pv;
    int speed;
    int dammage;
    int dammage_muerte;
} plane;

typedef struct soldats {
    unite soldat1;
    unite soldat2;
    unite soldat3;
    unite soldat4;
} soldats;

typedef struct object {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} obj;

typedef struct lifebar {
    sfTexture *bar_bg;
    sfTexture *bar_life;
    sfSprite *s_bar_bg;
    sfSprite *s_bar_life;
    sfVector2f pos;
    sfIntRect rect;
} lifebar;

typedef struct liste_chainee_mobs {
    unite mob;
    struct liste_chainee_mobs *next;
} lcm;

int my_strlen(char const *str);
int my_getnbr(char *str);
char *my_itoi(int nb);
int my_putstr(char const *str);
int my_strstr(char *str, char const *to_find);
void my_putchar(char c);
int gestion_error(int ac, char **av);
void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len);
int my_put_nbr(int nb);
int my_printf(const char *format, ...);
void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len);
void print_sprite(sfRenderWindow *window, el element);
el init_element(int posx, int posy, int rect_width, int rect_heigh, char *fil);
soldats init_soldats(int pv, int speed);
void move_soldat(unite *element, int offset, sfClock *clock, int *life, int dammage);
c init_clocks(void);
void rotate_soldat(el *element);
int play_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event);
obj init_object(char *file, int width, int height, int x, int y);
void display_obj(sfRenderWindow *window, obj o_object);
void display_btn(sfRenderWindow *window, obj o_object, int offset, int value, sfEvent event);
int mouse_on_sprite(sfVector2i mouse_pos, sfVector2f sprite_pos, int width, int height);
int play_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event);
int exit_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event);
void htp_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event);
void game(sfRenderWindow *window);
int menu(sfRenderWindow *window);
unite init_tank(int pv, int speed, char *file, sfVector2f pos);
void move_tank(unite *element, int offset, sfClock *clock, int *life, int dammage);
void rotate_tank(el *element);
int htp(sfRenderWindow *window);
void returnmenu_btn(sfRenderWindow *window, obj o_object, int offset, sfEvent event);
unite init_plane(int pv, int speed, char *file, sfVector2f pos);
void move_plane(unite *elementt, int offset, sfClock *clock, int *life, int dammage);
void rotate_plane(el *element);
int get_best_score(void);
void new_best_score(int score);
int btn_turret(sfRenderWindow *window, obj o_object, int target, sfEvent event, int *money);
lifebar init_bar(void);
void display_life(int life, lifebar health, sfRenderWindow *window);
void tower_cible_mob(slot *slot, lcm *liste, sfClock *clock, soldats *my_soldats, unite *tank1, unite *tank2, unite *plane1, unite *plane2);
lcm *init_liste_chainee_mobs(soldats soldats, unite tank, unite tank2, unite plane, unite plane2);
void print_error_txt(sfRenderWindow *window, char *str, sfVector2f pos, int len);
sfVector2f makepos(int x, int y);
int mouse_on_slot(sfVector2i mouse_pos, sfVector2f sprite_pos, int width, int height);
void print_pop(sfVector2i mouse_pos, int target, sfRenderWindow *window, int *money);
void pause_menu(int *is_pause, sfRenderWindow *window, sfEvent event);
void display_pause(sfRenderWindow *window);
int endgame(sfRenderWindow *window, int score, int highscore);
int pausemenu(sfRenderWindow *window, int score, int best_score);
void attack(sfClock *clock, slot *slot, unite *mob);
void print_score(sfRenderWindow *window, char *str, sfVector2f pos, int len);
sfMusic *play_sound(char *filepath, int vol);
void up_score_and_money(int *score, int *moula, soldats *my_soldats, unite *tank1, unite *tank2, unite *plane1, unite *plane2);
void print_text_origin(sfRenderWindow *window, char *str, sfVector2f pos, int len);
#endif