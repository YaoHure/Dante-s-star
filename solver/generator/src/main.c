/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/

#include "generator.h"

char change_char(char c)
{
    int random = 0;

    random = rand() % (static_y(-1) * 2 + 1);
    if (c == 'X' && random == 1)
        c = '*';
    return (c);
}

char **not_perfect(char **table)
{
    for (int y = 0; table[y] != NULL; y++)
        for (int x = 0; table[y][x] != '\0'; x++)
            table[y][x] = change_char(table[y][x]);
    return (table);
}

char **fonctionapart(char **table, int y, int x)
{
    int boolean = 0;

    for (int i = x; boolean != 1; i--) {
        printf("%d %d\n", y, i);
        table[y][i] = '*';
        if (y >= 1)
            boolean = (table[y - 1][i] == '*') ? 1 : boolean;
        if (i >= 1)
            boolean = (table[y][i - 1] == '*') ? 1 : boolean;
        if (i == 0) {
            y--;
            i = x;
        }
    }
    return (table);
}

char **make_exit(char **table)
{
    int y = static_y(-1) - 1;
    int x = static_x(-1) - 1;

    if ((y <= 1 || x <= 1) || table[x][y] == '*')
        return (table);
    table[y][x] = '*';
    if (table[y][x - 1] == 'X' && table[y - 1][x] == 'X') {
        table = fonctionapart(table, y, x);
    }
    return (table);
}

int main(int ac, char **av)
{
    int *false;
    node_t *node;
    char **table;

    if (error(ac, av) == 84)
        return (84);
    false = generate_list();
    node = init_chained_list();
    table = init_table(atoi(av[1]), atoi(av[2]));
    static_x(atoi(av[1]));
    static_y(atoi(av[2]));
    table[0][0] = '*';
    table = gen_loop(false, node, table);
    if (ac == 3)
        table = not_perfect(table);
    my_put_array(table);
    for (int i = 0; i < static_y(-1); i++)
        free(table[i]);
    free(table);
    free(false);
}
