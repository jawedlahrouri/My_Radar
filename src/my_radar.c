/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** main
*/

#include "../include/my.h"

int is_tty(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(env[i], "TERM=linux") == 0)
            return 1;
    }
    return 0;
}

void game_loop(sfRenderWindow *window, sfSprite *background,
    entity_t *entities, ath_t *ath)
{
    int is_running = 1;
    float passed_time = 0;

    while (is_running) {
        manage_events(window, &is_running);
        passed_time = sfTime_asSeconds(sfClock_restart(ath->clock));
        ath->time += passed_time;
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, background, NULL);
        draw_entities(window, entities);
        display_timer(window, ath->font, ath->time);
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv, char **env)
{
    sfRenderWindow *window = create_window(1920, 1080, "RADAR");
    sfSprite *background = create_sprite("assets/background.png", 1920, 1080);
    entity_t *entities = NULL;
    ath_t *ath = initialize_ath("assets/arial.ttf");

    if (is_tty(env) == 1)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_putstr("CREDIT : Jawed Lahrouri\n appuyez sur esc pour fermer\n");
        return 0;
    }
    if (!ath || parse_script(argv[1], &entities) == 84 || !window
        || !background || argc != 2)
        return 84;
    game_loop(window, background, entities, ath);
    destroy_window(window);
    return 0;
}
