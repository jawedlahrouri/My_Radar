/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** entity
*/

#include "../include/my.h"

void initialize_tower(tower_t *tower, char *line)
{
    int x = 0;
    int y = 0;
    int radius = 0;

    sscanf(line, "T %d %d %d", &x, &y, &radius);
    *tower = (tower_t){x, y, radius};
}

void initialize_plane(plane_t *plane, char *line)
{
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    int speed = 0;
    int delay = 0;

    sscanf(line, "A %d %d %d %d %d %d", &x_start, &y_start,
    &x_end, &y_end, &speed, &delay);
    *plane = (plane_t){x_start, y_start, x_end, y_end, speed,
    delay, 0, x_start, y_start};
}

entity_t *create_entity(char *line)
{
    char type;
    entity_t *entity = malloc(sizeof(entity_t));

    if (entity == NULL)
        return NULL;
    sscanf(line, "%c", &type);
    if (type == 'A') {
        entity->type = 'A';
        initialize_plane(&entity->aircraft, line);
    } else if (type == 'T') {
        entity->type = 'T';
        initialize_tower(&entity->tower, line);
    } else {
        free(entity);
        return NULL;
    }
    entity->next = NULL;
    return entity;
}

int executate_script(FILE *file, entity_t **entities, char **line, size_t *len)
{
    ssize_t read;
    entity_t *new_entity = NULL;

    while (1) {
        read = getline(line, len, file);
        if (read == -1)
            break;
        new_entity = create_entity(*line);
        if (new_entity == NULL)
            return 84;
        new_entity->next = *entities;
        *entities = new_entity;
    }
    return 0;
}

int parse_script(const char *filepath, entity_t **entities)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        return 84;
    if (executate_script(file, entities, &line, &len) == 84) {
        free(line);
        fclose(file);
        return 84;
    }
    free(line);
    fclose(file);
    return 0;
}
