/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "generator.h"

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
    if (y - 1 >= 0 && rand != 1)
        around += (table[y - 1][x] == '*') ? 1 : 0;
    if (y + 1 < y_l && rand != 0)
        around += (table[y + 1][x] == '*') ? 1 : 0;
    if (x - 1 >= 0 && rand != 3)
        around += (table[y][x - 1] == '*') ? 1 : 0;
    if (x + 1 < x_l && rand != 2)
        around += (table[y][x + 1] == '*') ? 1 : 0;
    around += (table[y][x] == '*') ? 1 : 0;
    around += check_around_bigger(table, y, x, rand);
    return ((around == 0) ? 0 : 1);
}

int check_if_available(node_t *node, char **table, int rand)
{
    int x = node->x;
    int y = node->y;
    int tmp = 0;

    y -= (rand == 0) ? 1 : 0;
    y += (rand == 1) ? 1 : 0;
    x -= (rand == 2) ? 1 : 0;
    x += (rand == 3) ? 1 : 0;
    tmp = check_around(table, y, x, rand);
    return (tmp);
}

int *clear_list(int *list)
{
    list[0] = -1;
    list[1] = -1;
    list[2] = -1;
    list[3] = -1;
    return (list);
}

char **gen_loop(int *false, node_t *node, char **table)
{
    int rand;

    srand(time(NULL));
    while (node != NULL) {
        rand = randomize_direction(false);
        if (check_if_available(node, table, rand) == 0) {
            node = push_node(node, rand);
            table[node->y][node->x] = '*';
            false = clear_list(false);
        } else {
            false[my_int_list_len(false)] = rand;
            if (my_int_list_len(false) >= 4) {
                false = clear_list(false);
                node = remove_node(node);
            }
        }
    }
    table = make_exit(table);
    return (table);
}