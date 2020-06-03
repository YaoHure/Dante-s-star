##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## DANTE
##

GENERATOR	=	generator/

SOLVER		= 	solver/

all:
		make -C $(GENERATOR)
		make -C $(SOLVER)

clean:
		make -C $(GENERATOR) clean
		make -C $(SOLVER) clean

fclean:		clean
		make -C $(GENERATOR) fclean
		make -C $(SOLVER) fclean

re:		fclean all

.PHONY:		all clean fclean re
