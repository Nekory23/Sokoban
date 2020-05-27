/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** controls
*/

#include "my.h"

void gest_down_collision(char **map, int i, int j)
{
    if (map[i + 2][j] != '#' && map[i + 2][j] != 'X') {
        map[i + 2][j] = 'X';
        map[i + 1][j] = 'P';
        map[i][j] = ' ';
    }
}

void move_player_down(char **map, int line_nbr, char *new_map)
{
    int len_line = 0;

    for (int i = 0, down = 0; i < line_nbr; i++) {
        len_line = my_strlen(map[i]);
        for (int j = 0; j <len_line; j++) {
            if (map[i][j] == 'P' && (map[i + 1][j] == ' ' || map[i + 1][j] == 'O')) {
                map[i + 1][j] = 'P';
                map[i][j] = ' ';
                down++;
                break;
            }
            if (map[i][j] == 'P' && map[i + 1][j] == 'X') {
                gest_down_collision(map, i, j);
                down++;
                break;
            }
        }
        if (down == 1)
            break;
    }
    display_map(map, line_nbr, new_map);
}

void gest_up_collision(char **map, int i, int j)
{
    if (map[i - 2][j] != '#' && map[i - 2][j] != 'X') {
        map[i - 2][j] = 'X';
        map[i - 1][j] = 'P';
        map[i][j] = ' ';
    }
}

void move_player_up(char **map, int line_nbr, char *new_map)
{
    int len_line = 0;

    for (int i = 0; i < line_nbr; i++) {
        len_line = my_strlen(map[i]);
        for (int j = 0; j < len_line; j++) {
            if (map[i][j] == 'P' && map[i - 1][j] == ' ') {
                map[i - 1][j] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i - 1][j] == 'O') {
                map[i - 1][j] = 'P';
                map[i][j] = ' ';
                break;
            }
            if (map[i][j] == 'P' && map[i - 1][j] == 'X') {
                gest_up_collision(map, i, j);
                break;
            }
        }
    }
    display_map(map, line_nbr, new_map);
}
