##
## EPITECH PROJECT, 2017
## makefile
## File description:
## gaspacho andalou
##

SRC	=	./src/globbings.c		\
		./src/my_str_to_wordtab.c	\
		./src/gnl.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hist

CFLAGS	=	-W -Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f ./src/*.o
	rm -f *~
	rm -f *~
	rm -f ./lib_printf/include/*~
	rm -f ./lib_printf/src/*.o
	rm -f ./lib_printf/src/*~
	rm -f vg*
	rm -f ./src/*~
	rm -f ./include/*~

fclean: clean
	rm -f $(NAME)
	rm -f ./lib_printf/libmy.a

re: fclean all
