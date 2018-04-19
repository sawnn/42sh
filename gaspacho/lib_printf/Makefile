##
## EPITECH PROJECT, 2017
## makefile
## File description:
## gaspacho andalou
##

SRC	=	./src/my_printf.c		\
		./src/my_putchar.c		\
		./src/my_put_nbr.c		\
		./src/my_putnbr_base.c		\
		./src/my_putnbr_longbase.c	\
		./src/my_putnbr_bin.c		\
		./src/my_put_unsigned_nbr.c	\
		./src/my_putstr.c		\
		./src/my_putstr_error.c		\
		./src/my_putchar_error.c	\
		./src/my_strlen.c		\
		./src/flag1.c			\
		./src/flag2.c			\
		./src/flag3.c			\
		./src/check_flag_printf.c	\
		./src/flag_big_s.c		

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f ./src/*.o
	rm -f ./src/*~
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
