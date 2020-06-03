/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "generator.h"

node_t *new_node(node_t *previous, int y, int x)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp == NULL)
        return (NULL);
    tmp->x = x;
    tmp->y = y;
    tmp->id = previous->id + 1;
    tmp->previous = previous;
    return (tmp);
}

node_t *remove_node(node_t *node)
{
    node_t *tmp;

    if (node == NULL)
        return (NULL);
    tmp = node->previous;
    free(node);
    node = tmp;
    return (node);
}

node_t *push_node(node_t *node, int rand)
{
    int y = node->y;
    int x = node->x;

    y -= (rand == 0) ? 1 : 0;
    y += (rand == 1) ? 1 : 0;
    x -= (rand == 2) ? 1 : 0;
    x += (rand == 3) ? 1 : 0;
    node = new_node(node, y, x);
    return (node);
}

int static_y(int y_new)
{
    static int y = 0;

    if (y_new != -1)
        y = y_new;
    return (y);
}

int static_x(int x_new)
{
    static int x = 0;

    if (x_new != -1)
        x = x_new;
    return (x);
}