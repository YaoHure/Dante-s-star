/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** node.c
*/

#include "solver.h"

int *generate_list(void)
{
    int *false = malloc(sizeof(int) * 5);

    if (false == NULL)
        return (false);
    false[0] = -1;
    false[1] = -1;
    false[2] = -1;
    false[3] = -1;
    false[4] = -1;
    return (false);
}

node_t ***node_table(char **table)
{
    node_t ***n_table = malloc(sizeof(node_t * ) * (my_tablen(table) + 1));
    int i = 0;
    int j = 0;

    for (i = 0; table[i] != NULL; i++) {
        n_table[i] = malloc(sizeof(node_t) * (strlen(table[i]) + 1));
        for (j = 0; table[i][j] != '\0'; j++) {
            n_table[i][j] = malloc(sizeof(node_t));
            n_table[i][j]->x = j;
            n_table[i][j]->y = i;
            n_table[i][j]->status = (table[i][j] == 'X') ? 3 : 0;
        }
        n_table[i][j] = NULL;
    }
    n_table[i] = NULL;
    return (n_table);
}
