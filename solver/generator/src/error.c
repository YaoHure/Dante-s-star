/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "generator.h"

int is_a_number_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int error(int ac, char **av)
{
    if (ac < 3 || ac > 4) {
        write(2, "Invalid number of arguments\n", 28);
        return (84);
    }
    if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        write(2, "Arguments error\n", 16);
        write(2, "./generator [height] [width] [perfect]\n", 49);
        return (84);
    }
    if (is_a_number_str(av[1]) == 0 || (is_a_number_str(av[2]) == 0)) {
        write(2, "The arguments must be number greather than 0\n", 45);
        return (84);
    }
    return ((atoi(av[1]) <= 0 || atoi(av[2]) <= 0) ? 84 : 0);
}
