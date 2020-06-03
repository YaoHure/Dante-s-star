##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makfile
##


NAME	 = solver

IDIR	 = include/
IDIR_MY	 = ./include

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -W

SRCS_DIR	= src/
SRCS_FILES	= check_file.c main.c my_str_to_word_array.c node_utilities.c randomize.c solve_loop.c error.c print_map.c check_solver.c node.c

SRCS     = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L $(LDIR) -l $(LNAME)

gdb:    $(OBJS)
	$(CC) -g -o debug $(SRCS_DIR)/$(SRCS_FILES) -I $(IDIR) -I $(IDIR_MY) -L $(LDIR) -l $(LNAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
