/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "generator.h"

int check_false_list(int result, int *list)
{
    for (int i = 0; i < 5; i++)
        if (result == list[i])
            return (0);
    return (1);
}

int randomize_direction(int *exception)
{
    int result = rand() % 4;

    for (; check_false_list(result, exception) != 1; result = rand() % 4);
    return (result);
}
