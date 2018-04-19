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
	cp my.h ../include/
	cp .gnl/libgnl.a libgnl.a
	cp .gnl/sample.c sample.c
	rm -rf *.o *~

clean:
	rm -f *.o *~

fclean: clean
	rm -f libmy.a
	rm -f libgnl.a
	rm -f sample.c

re:	fclean all
