/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** puzzle game on terminal
*/

#include "my.h"

void control_check(int g, char **map, int line_nbr, char *new_map)
{
    if (g == UP || g == KEY_UP)
        move_player_up(map, line_nbr, new_map);
    if (g == DOWN || g == KEY_DOWN)
        move_player_down(map, line_nbr, new_map);
    if (g == LEFT || g == KEY_LEFT)
        move_player_left(map, line_nbr, new_map);
    if (g == RIGHT || g == KEY_RIGHT)
        move_player_right(map, line_nbr, new_map);
}

void display_map(char **map, int line_nbr, char *new_map)
{
    int len_line = 0;
    int g;

    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        for (int i = 0; i != line_nbr; i++) {
            len_line = my_strlen(map[i]) / 2;
            mvprintw((LINES / 2) - line_nbr + i, (COLS / 2) - len_line, map[i]);
        }
        refresh();
        g = getch();
        if (g == ENTER)
            break;
        if (g == SPACE) {
            open_file(new_map);
            break;
        }
        control_check(g, map, line_nbr, new_map);
    }
    endwin();
}

void open_file(char *map)
{
    int fd;
    char *buffer;
    struct stat st;

    fd = open(map, O_RDONLY);
    stat(map, &st);
    buffer = malloc(st.st_size + 1);
    read(fd, buffer, st.st_size);
    fragment_map(buffer, map);
    free(buffer);
    close(fd);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(2, ERROR_ARGNBR, my_strlen(ERROR_ARGNBR));
        return (84);
    }
    if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help_display();
        return (0);
    }
    if (error_handling(av) == 84)
        return (84);
    open_file(av[1]);
    return (0);
}
