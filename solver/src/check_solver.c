/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** check_solver.c
*/

#include "solver.h"

int my_int_list_len(int *list)
{
    int i = 0;
    for (; list[i] != -1; i++);
    return (i);
}

int check_around(char **table, int y, int x, int rand)
{
    int around = 0;
    int x_l = static_x(-1);
    int y_l = static_y(-1);

    if (y < 0 || y >= y_l)
        return (1);
    else if (x < 0 || x >= x_l)
        return (1);
    if (y - 1 > 0 && rand != 1)
        around += (table[y - 1][x] == '*') ? 1 : 0;
    if (y + 1 < y_l && rand != 0)
        around += (table[y + 1][x] == '*') ? 1 : 0;
    if (x - 1 > 0 && rand != 3)
        around += (table[y][x - 1] == '*') ? 1 : 0;
    if (x + 1 < x_l && rand != 2)
        around += (table[y][x + 1] == '*') ? 1 : 0;
    around += (table[y][x] == '*') ? 1 : 0;
    return ((around == 0) ? 0 : 1);
}

int check_if_available(node_t *node, node_t ***nodes, int rand)
{
    int x = node->x;
    int y = node->y;
    int tmp = 0;

    y -= (rand == 0) ? 1 : 0;
    y += (rand == 1) ? 1 : 0;
    x -= (rand == 2) ? 1 : 0;
    x += (rand == 3) ? 1 : 0;
    if (y < 0 || y >= static_y(-1))
        return (0);
    if (x < 0 || x >= static_x(-1))
        return (0);
    return ((nodes[y][x]->status == 0) ? 1 : 0);
}
