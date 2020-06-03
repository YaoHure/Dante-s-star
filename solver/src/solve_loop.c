/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "solver.h"

int *clear_list(int *list)
{
    list[0] = -1;
    list[1] = -1;
    list[2] = -1;
    list[3] = -1;
    return (list);
}

node_t *push_node(node_t *node, node_t ***old_one, int rand)
{
    node_t *new_one;
    int y = node->y;
    int x = node->x;

    y -= (rand == 0) ? 1 : 0;
    y += (rand == 1) ? 1 : 0;
    x -= (rand == 2) ? 1 : 0;
    x += (rand == 3) ? 1 : 0;
    new_one = old_one[y][x];
    new_one->previous = node;
    node->status = 2;
    return (new_one);
}

node_t *remove_node(node_t *node)
{
    node->status = 10;
    node = node->previous;
    return (node);
}

char **solve_loop(int *false, node_t ***node, char **table)
{
    int rand;
    node_t *n_list = node[0][0];
    int x = strlen(table[0]);
    int y = my_tablen(table);

    static_x(x);
    static_y(y);
    n_list->status = 2;
    n_list->previous = NULL;
    srand(time(NULL));
    while (n_list->y != y - 1 || n_list->x != x - 1) {
        rand = randomize_direction(false);
        if (check_if_available(n_list, node, rand) == 1) {
            n_list = push_node(n_list, node, rand);
            false = clear_list(false);
        } else {
            false[my_int_list_len(false)] = rand;
            if (my_int_list_len(false) >= 4) {
                false = clear_list(false);
                n_list = remove_node(n_list);
            }
        }
    }
    node[y - 1][x - 1]->status = 2;
    for (; n_list != NULL; n_list = n_list->previous)
        table[n_list->y][n_list->x] = 'o';
    return (table);
}
