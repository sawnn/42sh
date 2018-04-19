##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/cd.c	\
		src/epur.c	\
		src/setenv.c	\
		src/unsetenv.c	\
		src/builtins.c	\
		src/error_handling.c	\
		src/redirection.c	\
		src/semicolons.c	\
		src/pipe.c	\
		src/getnextline.c	\
		src/pipe_fonction.c	\
		src/env.c

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my/
		gcc -o $(NAME) $(SRC) -L lib/ -lmy -g3

clean:
	$(RM) ./lib/my/*.o
	$(RM) $(OBJ)
	$(RM) *~

fclean:	clean
	$(RM)  $(NAME)

re:	fclean all
