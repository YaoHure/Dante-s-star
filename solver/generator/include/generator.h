/*
** EPITECH PROJECT, 2018
** Dante
** File description:
** Maxence Carpentier && Yaowanart Huré
*/


#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int x;
    int y;
    int id;
    struct node *previous;
} node_t;

int my_int_list_len(int *list);

// utilities.c

void my_put_array(char **array);

int *generate_list(void);

node_t *init_chained_list(void);

char **init_table(int x, int y);

// node_utilities.c

node_t *new_node(node_t *previous, int y, int x);

node_t *remove_node(node_t *node);

node_t *push_node(node_t *node, int rand);

int static_y(int y_new);

int static_x(int x_new);

// gen_loop.c

int my_int_list_len(int *list);

int check_around(char **table, int y, int x, int rand);

int check_if_available(node_t *node, char **table, int rand);

int *clear_list(int *list);

char **gen_loop(int *false, node_t *node, char **table);

//randomize.c

int check_false_list(int result, int *list);

int randomize_direction(int *exception);

// main.c

char **make_exit(char **table);

// error.c

int error(int ac, char **av);

int check_around_bigger(char **table, int y, int x, int rand);

#endif