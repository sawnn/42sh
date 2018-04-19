##
## EPITECH PROJECT, 2017
## Makefile_lib
## File description:
## lib
##


NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c *.c
	ar rc libmy.a *.o
	rm -rf *.o *~

clean:
	rm -f *.o *~

fclean: clean
	rm -f libmy.a

re:	fclean all
