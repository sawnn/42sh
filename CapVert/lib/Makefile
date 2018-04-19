##
## EPITECH PROJECT, 2017
## makefile
## File description:
## make
##

SRC	=	flag_b.c		\
		flag_c.c		\
		flag_d.c		\
		flag_i.c		\
		flag_mod.c		\
		flag_o.c		\
		flag_p.c		\
		flag_s.c		\
		flag_u.c		\
		flag_x.c		\
		flag_x_big.c		\
		flag_s_big.c		\
		my_printf.c		\
		my_putchar.c		\
		my_put_nbr_base.c	\
		my_put_nbr_base_p.c	\
		my_strlen.c		\
		my_printf_bis.c		\
		get_next_line.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
clean:
	rm -f $(OBJ)
	rm -f ./src/*~
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	$(NAME) clean all
