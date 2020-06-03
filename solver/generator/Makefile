##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makfile
##


NAME	 = generator

IDIR	 = include/
IDIR_MY	 = ./include

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -W

SRCS_DIR	= src/
SRCS_FILES	= check_directions.c error.c gen_loop.c main.c node_utilities.c randomize.c utilities.c

SRCS     = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	 = $(SRCS:.c=.o)

RM	 = rm -f

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

gdb:    $(OBJS)
	$(CC) -g -o debug $(SRCS_DIR)/$(SRCS_FILES) -I $(IDIR) -I $(IDIR_MY)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
