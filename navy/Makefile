##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	sig.c	\
		end.c	\
		main.c	\
		start.c	\
		create.c	\
		game_sig.c	\
		src/puterror.c	\
		src/my_strcmp.c	\
		src/my_getunbr.c	\
		src/get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

LDFLAGS	=	-lprint

CFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME):	lib $(OBJ)
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L ./my_printf/ $(LDFLAGS)

lib:
	@make -C my_printf/

clean:
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C my_printf/
	@rm -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re
