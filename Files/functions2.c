/*
** EPITECH PROJECT, 2022
** functions2.c
** File description:
** functions2.c
*/

#include "../Includes/my.h"

sfSound *init_sound(char *filepath)
{
    sfSoundBuffer *buff_sound;
    buff_sound = sfSoundBuffer_createFromFile(filepath);
    sfSound *sound = sfSound_create();
    sfSound_setBuffer(sound, buff_sound);
    return (sound);
}