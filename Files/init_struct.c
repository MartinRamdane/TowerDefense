/*
** EPITECH PROJECT, 2021
** init_sruct.c
** File description:
** runner
*/

#include "../Includes/my.h"

lcm *init_liste_chainee_mobs(soldats soldats, unite tank, unite tank2, unite plane, unite plane2)
{
    lcm *liste = NULL;
    lcm *liste1 = malloc(sizeof(lcm));
    liste1 -> mob = plane2;
    liste1 -> next = liste;
    lcm *liste2 = malloc(sizeof(lcm));
    liste2 -> mob = plane;
    liste2 -> next = liste1;
    lcm *liste3 = malloc(sizeof(lcm));
    liste3 -> mob = tank2;
    liste3 -> next = liste2;
    lcm *liste4 = malloc(sizeof(lcm));
    liste4 -> mob = tank;
    liste4 -> next = liste3;
    lcm *liste5 = malloc(sizeof(lcm));
    liste5 -> mob = soldats.soldat1;
    liste5 -> next = liste4;
    lcm *liste6 = malloc(sizeof(lcm));
    liste6 -> mob = soldats.soldat2;
    liste6 -> next = liste5;
    lcm *liste7 = malloc(sizeof(lcm));
    liste7 -> mob = soldats.soldat3;
    liste7 -> next = liste6;
    lcm *liste8 = malloc(sizeof(lcm));
    liste8 -> mob = soldats.soldat4;
    liste8 -> next = liste7;
    return liste8;
}

unite init_soldat(int pv, int speed, char *file, sfVector2f pos)
{
    sfVector2f origin = {64, 64};
    unite my_soldat;
    my_soldat.typeunit = 1;
    my_soldat.pv = pv;
    my_soldat.speed = speed;
    my_soldat.dammage = 25;
    my_soldat.sprite = init_element(pos.x, pos.y, 128, 128, file);
    my_soldat.on_life = 1;
    sfSprite_setOrigin(my_soldat.sprite.sprite, origin);
    sfSprite_rotate(my_soldat.sprite.sprite, 90);
    my_soldat.sprite.angle = 90;
    return my_soldat;
}

unite init_tank(int pv, int speed, char *file, sfVector2f pos)
{
    sfVector2f origin = {64, 64};
    unite my_tank;
    my_tank.typeunit = 2;
    my_tank.pv = pv;
    my_tank.speed = speed;
    my_tank.dammage = 100;
    my_tank.sprite = init_element(pos.x, pos.y, 128, 128, file);
    my_tank.on_life = 1;
    sfSprite_setOrigin(my_tank.sprite.sprite, origin);
    sfSprite_rotate(my_tank.sprite.sprite, 90);
    my_tank.sprite.angle = 90;
    return my_tank;
}

unite init_plane(int pv, int speed, char *file, sfVector2f pos)
{
    sfVector2f origin = {64, 64};
    unite my_plane;
    my_plane.typeunit = 3;
    my_plane.pv = pv;
    my_plane.speed = speed;
    my_plane.dammage = 50;
    my_plane.sprite = init_element(pos.x, pos.y, 128, 128, file);
    my_plane.on_life = 1;
    sfSprite_setOrigin(my_plane.sprite.sprite, origin);
    sfSprite_rotate(my_plane.sprite.sprite, 90);
    my_plane.sprite.angle = 90;
    return my_plane;
}

soldats init_soldats(int pv, int speed)
{
    sfVector2f pos1 = {250, -100};
    sfVector2f pos2 = {250, -175};
    sfVector2f pos3 = {250, -250};
    sfVector2f pos4 = {250, -325};
    soldats my_soldats;
    my_soldats.soldat1 = init_soldat(pv, speed, "Pictures/mobs/soldat1.png", pos1);
    my_soldats.soldat2 = init_soldat(pv, speed, "Pictures/mobs/soldat2.png", pos2);
    my_soldats.soldat3 = init_soldat(pv, speed, "Pictures/mobs/soldat3.png", pos3);
    my_soldats.soldat4 = init_soldat(pv, speed, "Pictures/mobs/soldat4.png", pos4);
    return my_soldats;
}

el init_element(int posx, int posy, int rect_width, int rect_heigh, char *fil)
{
    el element;
    element.texture = sfTexture_createFromFile(fil, NULL);
    element.sprite = sfSprite_create();
    element.pos.x = posx;
    element.pos.y = posy;
    element.rect.height = rect_heigh;
    element.rect.left = 0;
    element.rect.width = rect_width;
    element.rect.top = 0;
    sfSprite_setPosition(element.sprite, element.pos);
    return element;
}

c init_clocks(void)
{
    c clocks;
    clocks.clock1 = sfClock_create();
    clocks.clock2 = sfClock_create();
    clocks.clock3 = sfClock_create();
    clocks.clock4 = sfClock_create();
    clocks.clock5 = sfClock_create();
    clocks.clock6 = sfClock_create();
    clocks.clock7 = sfClock_create();
    clocks.clock8 = sfClock_create();
    clocks.clock9 = sfClock_create();
    clocks.clock10 = sfClock_create();
    clocks.clock11 = sfClock_create();
    clocks.clock12 = sfClock_create();
    clocks.clock13 = sfClock_create();
    clocks.clock14 = sfClock_create();
    clocks.clock15 = sfClock_create();
    clocks.clock16 = sfClock_create();
    clocks.clock17 = sfClock_create();
    clocks.clock18= sfClock_create();
    clocks.clock19 = sfClock_create();
    clocks.clock20 = sfClock_create();
    clocks.clock21 = sfClock_create();
    clocks.clock22 = sfClock_create();
    clocks.clock23 = sfClock_create();
    return clocks;
}
