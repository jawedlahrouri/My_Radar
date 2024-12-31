/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** draw_entity
*/

#include "../include/my.h"


void draw_aircraft(sfRenderWindow *window, plane_t *aircraft)
{
    sfRectangleShape *aircraft_shape = sfRectangleShape_create();
    sfVector2f position = {aircraft->x_start, aircraft->y_start};
    sfVector2f size = {20, 20};

    if (!aircraft_shape)
        return;
    sfRectangleShape_setPosition(aircraft_shape, position);
    sfRectangleShape_setSize(aircraft_shape, size);
    sfRectangleShape_setFillColor(aircraft_shape, sfBlue);

    sfRenderWindow_drawRectangleShape(window, aircraft_shape, NULL);
    sfRectangleShape_destroy(aircraft_shape);
}


void draw_tower(sfRenderWindow *window, tower_t *tower)
{
    sfCircleShape *tower_shape = sfCircleShape_create();
    sfVector2f position = {tower->x, tower->y};

    if (!tower_shape)
        return;
    sfCircleShape_setPosition(tower_shape, position);
    sfCircleShape_setRadius(tower_shape, tower->radius);
    sfCircleShape_setFillColor(tower_shape, sfTransparent);
    sfCircleShape_setOutlineColor(tower_shape, sfWhite);
    sfCircleShape_setOutlineThickness(tower_shape, 2);
    sfRenderWindow_drawCircleShape(window, tower_shape, NULL);
    sfCircleShape_destroy(tower_shape);
}


void draw_entities(sfRenderWindow *window, entity_t *entities)
{
    for (entity_t *current = entities; current != NULL; current = current->next) {
        if (current->type == 'A') {
            draw_aircraft(window, &current->aircraft);
        } else if (current->type == 'T') {
            draw_tower(window, &current->tower);
        }
    }
}
