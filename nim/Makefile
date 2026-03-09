##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	game.c	\
		main.c	\
		check.c	\
		ai/take_rand.c	\
		ai/computer.c	\
		src/name.c	\
		src/getunbr.c	\
		src/putstr.c	\
		src/get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

NAME	=	nim

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
