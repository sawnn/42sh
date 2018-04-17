##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## gaspacho andalou
##

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:	$(NAME)

CFLAGS	= -I include -g3

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)
	rm -f include/*~
	rm -f src/*~
	rm -f include/*.o
	rm -f ./*~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

