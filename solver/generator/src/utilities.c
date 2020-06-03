/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "generator.h"

void my_put_array(char **array)
{
    int limit = static_y(-1);

    printf("%s", array[0]);
    for (int i = 1; i < limit; i++)
        printf("\n%s", array[i]);
}

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

node_t *init_chained_list(void)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return (NULL);
    node->previous = NULL;
    node->id = 0;
    node->x = 0;
    node->y = 0;
    return (node);
}

char **init_table(int x, int y)
{
    char **table = malloc(sizeof(char *) * (y + 1));
    int i = 0;
    int j = 0;

    if (table == NULL)
        return (table);
    for (i = 0; i < y; i++) {
        table[i] = malloc(sizeof(char) * (x + 1));
        for (j = 0; j < x; j++)
            table[i][j] = 'X';
        table[i][j] = '\0';
    }
    table[i] = NULL;
    return (table);
}

int check_around_bigger(char **table, int y, int x, int rand)
{
    int around = 0;
    int x_l = static_x(-1);
    int y_l = static_y(-1);

    if (y - 2 >= 0 && rand == 0)
        around += (table[y - 2][x] == '*') ? 1 : 0;
    if (y + 2 < y_l && rand == 1)
        around += (table[y + 2][x] == '*') ? 1 : 0;
    if (x - 2 >= 0 && rand == 2)
        around += (table[y][x - 2] == '*') ? 1 : 0;
    if (x + 2 < x_l && rand == 3)
        around += (table[y][x + 2] == '*') ? 1 : 0;
    return ((around == 0) ? 0 : 1);
}