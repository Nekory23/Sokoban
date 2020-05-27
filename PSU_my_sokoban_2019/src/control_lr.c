/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** right and left movement
*/

#include "my.h"

void gest_left_collision(char **map, int i, int j)
{
    if (map[i][j - 2] != '#' && map[i][j - 2] != 'X') {
        map[i][j - 2] = 'X';
        map[i][j - 1] = 'P';
        map[i][j] = ' ';
    }
}

void move_player_left(char **map, int line_nbr, char *new_map)
{
    int len_line = 0;

    for (int i = 0; i < line_nbr; i++) {
        len_line = my_strlen(map[i]);
        for (int j = 0; j < len_line; j++) {
            if (map[i][j] == 'P' && map[i][j - 1] == ' ') {
                map[i][j - 1] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i][j - 1] == 'O') {
                map[i][j - 1] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i][j - 1] == 'X') {
                gest_left_collision(map, i, j);
                break;
            }
        }
    }
    display_map(map, line_nbr, new_map);
}

void gest_right_collision(char **map, int i, int j)
{
    if (map[i][j + 2] != '#' && map[i][j + 2] != 'X') {
        map[i][j + 2] = 'X';
        map[i][j + 1] = 'P';
        map[i][j] = ' ';
    }
}

void move_player_right(char **map, int line_nbr, char *new_map)
{
    int len_line = 0;

    for (int i = 0; i < line_nbr; i++) {
        len_line = my_strlen(map[i]);
        for (int j = 0; j < len_line; j++) {
            if (map[i][j] == 'P' && map[i][j + 1] == ' ') {
                map[i][j + 1] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i][j + 1] == 'O') {
                map[i][j + 1] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i][j + 1] == 'X') {
                gest_right_collision(map, i, j);
                break;
            }
        }
    }
    display_map(map, line_nbr, new_map);
}
