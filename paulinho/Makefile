##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## minishell
##

SRC	=	src/*.c

NAME	=	mysh

all:	makelib $(NAME)

makelib :
		(cd ./lib && make re)

$(NAME) :
	gcc -g3 -o $(NAME) $(SRC) -L ./lib -lmy -L ./lib -lgnl

clean:
	rm -rf *~

fclean:	clean
	rm -rf $(NAME)
	(cd ./lib && make fclean)

re:	fclean all
