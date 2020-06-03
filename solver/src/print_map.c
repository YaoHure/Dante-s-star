/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** print_map.c
*/

#include "solver.h"

void my_put_array(char **array)
{
    int limit = static_y(-1);

    printf("%s", array[0]);
    for (int i = 1; i < limit; i++)
        printf("\n%s", array[i]);
}

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}
