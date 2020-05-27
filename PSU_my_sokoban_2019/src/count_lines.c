/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** count the number of lines in the map
*/

#include "my.h"

int count_lines(char *buffer)
{
    int line_nbr = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line_nbr = line_nbr + 1;
    return (line_nbr);
}
