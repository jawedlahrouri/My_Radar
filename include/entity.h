/*
** EPITECH PROJECT, 2024
** entity.h
** File description:
** linked list with the entities
*/

#include "plane.h"
#include "tower.h"

#ifndef ENTITY_H_
    #define ENTITY_H_

typedef struct entity_t {
    char type;
    union {
        plane_t aircraft;
        tower_t tower;
    };
    struct entity_t *next;
} entity_t;
#endif
