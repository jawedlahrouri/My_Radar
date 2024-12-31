/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** main
*/

#include "../include/my.h"

void game_loop(sfRenderWindow *window, sfSprite *background, entity_t *entities)
{
    sfEvent event;
    int is_running = 1;

    while (is_running) {
        manage_events(window, &is_running);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, background, NULL);
        draw_entities(window, entities); 
        sfRenderWindow_display(window);
    }
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = create_window(1920, 1080, "RADAR");
    sfSprite *background = create_sprite("assets/background.jpg", 1920, 1080);
    entity_t *entities = NULL;

    if (parse_script(argv[1], &entities) == 84)
        return 84;
    if (argc != 2)
        return 84;
    if (!window || !background)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        my_putstr("CREDIT : Jawed Lahrouri\n");
        return 0;
    }
    game_loop(window, background, entities);
    destroy_window(window);
    return 0;
}
