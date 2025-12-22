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
	@make -C my_printf
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L ./my_printf/ -lmy_printf

clean:
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C my_printf
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
