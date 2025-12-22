##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	print.c	\
		src/printptr.c	\
		src/printstr.c	\
		src/printchar.c	\
		src/print_nbr.c	\
		src/choose_base.c	\
		src/print_nbr_base.c	\
		src/print_octal_str.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

NAME	=	libmy_printf.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
