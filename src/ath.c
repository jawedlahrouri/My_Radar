/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** ath
*/

#include "../include/my.h"

void display_timer(sfRenderWindow *window, sfFont *font, float time)
{
    sfText *text = sfText_create();
    char buffer[6];
    int minute = (int)time / 60;
    int second = (int)time % 60;

    buffer[0] = (minute / 10) + '0';
    buffer[1] = (minute % 10) + '0';
    buffer[2] = ':';
    buffer[3] = (second / 10) + '0';
    buffer[4] = (second % 10) + '0';
    buffer[5] = '\0';
    sfText_setString(text, buffer);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, (sfVector2f){1790, 10});
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
