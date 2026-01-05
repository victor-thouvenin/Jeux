##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main.cpp	\
		board.cpp	\
		ai_play.cpp	\
		update_map.cpp	\
		Vector_convert.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

NAME	=	gomoku

CXXFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
