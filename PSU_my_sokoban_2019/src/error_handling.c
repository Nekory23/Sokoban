/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** error_handling
*/

#include "my.h"

int is_file_valid(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'P' || buffer[i] == 'O' || buffer[i] == ' ')
            i++;
        else if (buffer[i] == '#' || buffer[i] == 'X' || buffer[i] == '\n')
            i++;
        else {
            write(2, ERROR_MAP, my_strlen(ERROR_MAP));
            return (84);
        }
    }
    return (0);
}

int error_handling(char **av)
{
    int fd;
    char *buffer;
    int rd;
    struct stat st;

    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(2, ERROR_OPEN, my_strlen(ERROR_OPEN));
        return (84);
    }
    stat(av[1], &st);
    buffer = malloc(st.st_size + 1);
    rd = read(fd, buffer, st.st_size);
    if (rd == -1 || rd == 0) {
        write(2, ERROR_READ, my_strlen(ERROR_READ));
        return (84);
    }
    if (is_file_valid(buffer) == 84)
        return (84);
    close(fd);
    return (0);
}
