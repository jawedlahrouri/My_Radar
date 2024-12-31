/*
** EPITECH PROJECT, 2024
** plane.h
** File description:
** all plane info
*/

#ifndef PLANE_H_
    #define PLANE_H_

typedef struct plane_t {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int speed;
    int delay;
    int is_flying;
    float current_x;
    float current_y;

} plane_t;
#endif
