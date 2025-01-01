/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** window
*/

#include "../include/my.h"

sfRenderWindow *create_window(int width, int height, char *title)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfClose
        | sfFullscreen, NULL);

    sfRenderWindow_setFramerateLimit(window, 120);
    return window;
}

void destroy_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}
