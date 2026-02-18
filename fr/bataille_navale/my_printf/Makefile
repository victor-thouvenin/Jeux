##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		src/my_putptr.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/my_find_char.c	\
		src/my_choose_base.c	\
		src/my_putnbr_base.c	\
		src/my_put_octal_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libprint.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

tests_run:	$(OBJ)
	@gcc -o unit_tests $(OBJ) tests/test_printf.c --coverage -lcriterion
	@./unit_tests ; gcov test_printf.c ; make clean
	@rm unit_tests test_printf.gcda test_printf.gcno test_printf.c.gcov

re:	fclean all

.PHONY: all clean fclean tests_run re
