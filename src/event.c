/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** event_handling
*/

#include "../include/my.h"

void manage_events(sfRenderWindow *window, int *is_running)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            *is_running = 0;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}
