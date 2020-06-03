/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "solver.h"

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