##
## EPITECH PROJECT, 2017
## 42sh
## File description:
## Makefile
##

SRC	=	src/*.c

NAME	=	42sh

all:	makelib $(NAME)

makelib :
		(cd ./lib && make re)

$(NAME) :
	gcc -g3 -Wall -Werror -Wextra -o $(NAME) $(SRC) -L ./lib -lmy

clean:
	rm -rf *~

fclean:	clean
	rm -rf $(NAME)
	(cd ./lib && make fclean)

re:	fclean all
