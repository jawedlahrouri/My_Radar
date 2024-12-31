/*
** EPITECH PROJECT, 2024
** zone.h
** File description:
** zone info
*/

#include "entity.h"

#ifndef ZONE_H_
    #define ZONE_H_

typedef struct zone_t {
    int x_min;
    int x_max;
    int y_min;
    int y_max;
    entity_t *entities;
} zone_t;
#endif
