/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** fragment the map
*/

#include "my.h"

void fragment_map(char *buffer, char *new_map)
{
    int lines = count_lines(buffer);
    char **map = malloc(sizeof(char *) * lines);
    int temp = 0;
    int k = 0;

    for (int j = 0; buffer[temp] != '\0'; temp++) {
        if (buffer[temp] == '\n')
            j++;
        map[j] = malloc(sizeof(char) * (temp + 1));
    }
    temp = 0;
    for (int j = 0; buffer[temp] != '\0'; temp++, k++) {
        if (buffer[temp] == '\n') {
            map[j][temp] = '\0';
            j++;
            temp++;
            k = 0;
        }
        map[j][k] = buffer[temp];
    }
    display_map(map, lines, new_map);
}
