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
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(window);
        *is_running = 0;
    }
}

void display_timer(sfRenderWindow *window, sfFont *font, float time)
{
    sfText *text = sfText_create();
    int minute = (int)time / 60;
    int second = (int)time % 60;
    char buffer[16];
    sfVector2f position = {10, 10};

    if (!text || !font)
        return;
    snprintf(buffer, sizeof(buffer), "%02d:%02d", minute, second);
    sfText_setString(text, buffer);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void display_fps(sfRenderWindow *window, sfFont *font, float fps)
{
    sfText *text = sfText_create();
    sfVector2f position = {1790, 10};
    char buffer[16];

    if (!text || !font)
        return;
    snprintf(buffer, sizeof(buffer), "FPS: %.0f", fps);
    sfText_setString(text, buffer);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

ath_t *initialize_ath(const char *font_path)
{
    ath_t *ath = malloc(sizeof(ath_t));

    if (!ath)
        return NULL;
    ath->clock = sfClock_create();
    ath->time = 0.0f;
    ath->font = sfFont_createFromFile(font_path);
    if (!ath->clock || !ath->font) {
        if (ath->clock)
            sfClock_destroy(ath->clock);
        if (ath->font)
            sfFont_destroy(ath->font);
        free(ath);
        return NULL;
    }
    return ath;
}
