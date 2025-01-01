/*
** EPITECH PROJECT, 2024
** .h
** File description:
** stuct
*/

#include "my.h"
#include <stdarg.h>

#ifndef ATH_H_
    #define ATH_H_

typedef struct ath_s {
    sfClock *clock;
    float time;
    sfFont *font;
} ath_t;
#endif
