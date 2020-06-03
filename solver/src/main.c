/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** main.c
*/

#include "solver.h"

void free_map(node_t ***n_table, char **table, int *list)
{
    int i = 0;
    int y = 0;

    for (i = 0; n_table[i] != NULL; i++) {
        for (y = 0; n_table[y] != NULL; y++) {
            free(n_table[i][y]);
        }
        free(n_table[i]);
    }
    free(n_table);
    for (i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
    free(list);
}

int main(int ac, char **av)
{
    char **table;
    node_t ***n_table;
    int *list;

    if (ac != 2) {
        write(2, "Arguments error\n", 16);
        write(2, "./solver [map]\n", 15);
        return (84);
    }
    table = get_file(av[1]);
    if (error(ac, av) == 84)
        return (84);
    n_table = node_table(table);
    list = generate_list();
    if (table[my_tablen(table) - 1][strlen(table[0]) - 1] == 'X')
        return (0);
    solve_loop(list, n_table, table);
    my_put_array(table);
    free_map(n_table, table, list);
    return (0);
}
