/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Header avec les fonctions
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "entity.h"
    #include "plane.h"
    #include "tower.h"
    #include "zone.h"
    #include "ath.h"
int main(int argc, char **argv);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_putchar(char c);
void flag_d(va_list list);
void flag_o(va_list list);
void flag_s(va_list list);
void flag_i(va_list list);
void flag_c(va_list list);
void flag_percent(va_list list);
void flag_x2(va_list list);
void flag_x(va_list list);
int flag_detector(const char *format, int i, va_list list);
int my_printf(const char *format, ...);
void initialize_tower(tower_t *tower, char *line);
void initialize_plane(plane_t *plane, char *line);
entity_t *create_entity(char *line);
int executate_script(FILE *file, entity_t **entities,
    char **line, size_t *len);
int parse_script(const char *filepath, entity_t **entities);
sfSprite *create_sprite(char *filepath, int x, int y);
void destroy_window(sfRenderWindow *window);
sfRenderWindow *create_window(int width, int height, char *title);
void manage_events(sfRenderWindow *window, int *is_running);
void draw_entities(sfRenderWindow *window, entity_t *entities);
void draw_tower(sfRenderWindow *window, tower_t *tower);
void draw_aircraft(sfRenderWindow *window, plane_t *plane);
void display_timer(sfRenderWindow *window, sfFont *font, float time);
void display_fps(sfRenderWindow *window, sfFont *font, float fps);
ath_t *initialize_ath(const char *font_path);
#endif
