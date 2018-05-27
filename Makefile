##
## EPITECH PROJECT, 2017
## 42sh
## File description:
## Makefile
##

SRC	=	src/builtins/*.c	\
		src/parsing/*.c		\
		src/path/*.c		\
		src/utils/*.c		\
		src/exec/*.c		\
		src/bonus/*.c		\
		src/main.c

NAME	=	42sh

all:	makelib $(NAME)

makelib :
		(cd ./lib && make re)

$(NAME) :
	cp ./include/my_tree.txt ./include/my_tree.a
	gcc -g3 -Wall -Werror -Wextra -o $(NAME) $(SRC) -L ./lib -lmy ./include/my_tree.a

clean:
	rm -rf *~

fclean:	clean
	rm -rf $(NAME)
	(cd ./lib && make fclean)
	(cp ./include/my_tree.txt ./include/my_tree.a)
	(cd ./include && rm my_tree.a)

re:	fclean all
