/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void fragment_map(char *buffer, char *new_map);
int count_lines(char *buffer);
void display_map(char **map, int line_nbr, char *new_map);
void open_file(char *map);

void move_player_up(char **map, int line_nbr, char *new_map);
void gest_up_collision(char **map, int i, int j);
void move_player_down(char **map, int line_nbr, char *new_map);
void gest_down_collision(char **map, int i, int j);
void move_player_left(char **map, int line_nbr, char *new_map);
void gest_left_collision(char **map, int i, int j);
void move_player_right(char **map, int line_nbr, char *new_map);
void gest_right_collision(char **map, int i, int j);

int error_handling(char **av);
void help_display(void);

int my_strlen(char const *str);
void my_putstr(char const *str);
void my_putchar(char c);

#define UP 122
#define	DOWN 115
#define	LEFT 113
#define	RIGHT 100

#define SPACE 32
#define ENTER 10

#define ERROR_MAP "The map is invalid\n"
#define ERROR_ARGNBR "This program must take only the map as an argument\n"
#define ERROR_OPEN "The program could not open the file\n"
#define ERROR_READ "The program could not read the file\n"

#endif
