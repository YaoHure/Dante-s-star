/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** error.c
*/

#include "solver.h"

int verif_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && str[i] != '*' && str[i] != 'X')
            return (0);
    }
    return (1);
}

int verif_map(char **map, int size)
{
    for (int i = 0; i < size; i++) {
        if (verif_char(map[i]) == 0)
            return (0);
    }
    return (1);
}

int error(int ac, char **av)
{
    char *file_name = av[1];

    if (!file_name || open(file_name, O_RDONLY) <= 0) {
        write(2, "Check the file\n", 15);
        return (84);
    }
    return (0);
}
