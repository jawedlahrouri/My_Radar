/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** draw_entity
*/

#include "../include/my.h"


void draw_plane(sfRenderWindow *window, plane_t *plane)
{
    sfRectangleShape *plane_shape = sfRectangleShape_create();
    sfVector2f position = {plane->x_start, plane->y_start};
    sfVector2f size = {20, 20};

    if (!plane_shape)
        return;
    sfRectangleShape_setPosition(plane_shape, position);
    sfRectangleShape_setSize(plane_shape, size);
    sfRectangleShape_setFillColor(plane_shape, sfWhite);
    sfRenderWindow_drawRectangleShape(window, plane_shape, NULL);
    sfRectangleShape_destroy(plane_shape);
}

void draw_tower(sfRenderWindow *window, tower_t *tower)
{
    sfCircleShape *tower_shape = sfCircleShape_create();
    sfVector2f position = {tower->x, tower->y};

    if (!tower_shape)
        return;
    sfCircleShape_setPosition(tower_shape, position);
    sfCircleShape_setRadius(tower_shape, tower->radius);
    sfCircleShape_setFillColor(tower_shape, sfWhite);
    sfCircleShape_setOutlineColor(tower_shape, sfRed);
    sfCircleShape_setOutlineThickness(tower_shape, 2);
    sfRenderWindow_drawCircleShape(window, tower_shape, NULL);
    sfCircleShape_destroy(tower_shape);
}

void draw_entities(sfRenderWindow *window, entity_t *entities)
{
    for (entity_t *current = entities; current != NULL;
        current = current->next) {
        if (current->type == 'A')
            draw_plane(window, &current->plane);
        if (current->type == 'T')
            draw_tower(window, &current->tower);
    }
}
