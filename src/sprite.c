/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** sprite
*/

#include "../include/my.h"

sfSprite *create_sprite(char *filepath, int x, int y)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfIntRect area = {0, 0, x, y};
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, area);
    sfSprite_setScale(sprite, scale);
    return sprite;
}