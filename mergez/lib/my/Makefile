##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	my_flag_b.c			\
		my_flag_c.c			\
		my_flag_d.c			\
		my_flag_modulo.c			\
		my_flag_o.c			\
		my_flag_p.c			\
		my_flag_s.c			\
		my_flag_ss.c			\
		my_flag_u.c			\
		my_flag_x.c			\
		my_flag_xx.c			\
		my_printf.c			\
		my_getnbr.c			\
		my_putchar.c			\
		my_strcmp.c			\
		my_putstr.c			\
		my_strlen.c			\
		my_strcpy.c			\
		my_strcat.c			\
		my_str_to_wordtab.c		\
		my_strncmp.c			\
		my_strdup.c			\
		my_str_isalpha.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-g3

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
