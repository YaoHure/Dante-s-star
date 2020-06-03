/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** solver.h
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

typedef struct node {
    int x;
    int y;
    int status;
    struct node *previous;
} node_t;

int my_int_list_len(int *list);

// utilities.c

void my_put_array(char **array);

int *generate_list(void);

node_t *init_chained_list(void);

char **init_table(int x, int y);

// node_utilities.c


node_t *remove_node(node_t *node);

int static_y(int y_new);

int static_x(int x_new);

// gen_loop.c

int my_int_list_len(int *list);

int check_around(char **table, int y, int x, int rand);

int check_if_available(node_t *node, node_t ***nodes, int rand);

int *clear_list(int *list);

char **gen_loop(int *false, node_t *node, char **table);

// randomize.c

int check_false_list(int result, int *list);

int randomize_direction(int *exception);

// my_str_to_word_array.c

char *duplicate_str(char *dest, char *src, int begin_value, int end_value);

int is_alphanumeric(char c, char separator);

int delimiter_counter(char *str, char separator);

char **my_str_to_word_array(char *str, char separator);

// check_file.c

int check_file(char *file);

char **get_file(char *path);

char **solve_loop(int *false, node_t ***node, char **table);

void print_map(node_t ***n_table);

//error.c

int error(int ac, char **av);

//print_map.c

int my_tablen(char **tab);

node_t ***node_table(char **table);

#endif
