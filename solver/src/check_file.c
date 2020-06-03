/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** check_file.c
*/

#include "solver.h"

int check_file(char *file)
{
    int map = 0;
    int line = 0;
    int tmp = 0;

    if (file == NULL)
        return (84);
    map = strlen(file);
    for (int i = 0; file[i]; i++) {
        if ((file[i] != '*' || file[i] != 'X') && file[i] != '\n')
            return (84);
        line += (file[i] == '\n') ? 1 : 0;
        if (line != 0 && file[i] == '\n' && i - (line * map) - tmp != 0)
            return (84);
        tmp += (line != 0 && file[i] == '\n') ? 1 : 0;
    }
    return (0);
}

char **get_file(char *path)
{
    char *s;
    struct stat buf;
    char **table;
    int fd = open(path, O_RDONLY);
    int size = 0;

    stat(path, &buf);
    s = malloc(sizeof(char) * buf.st_size + 1);
    size = read(fd, s, buf.st_size);
    if (size == -1)
        return (NULL);
    s[size] = '\0';
    table = my_str_to_word_array(s, '\n');
    free(s);
    close(fd);
    return (table);
}
