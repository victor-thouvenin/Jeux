##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		check.c	\
		screen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	sokoban

CFLAGS	=	-Wall -Wextra

LFLAGS	=	-lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
