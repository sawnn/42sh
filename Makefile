##
## EPITECH PROJECT, 2018
## ok
## File description:
## ok
##

NAME	= 42sh

CC	= gcc -g3

VAL	= -g3

RM	= rm -f

SRCS	=	./src/main.c \
		./src/my_str_to_word_array.c \
		./src/my_str_to_word_tab_sep.c \
		./src/builtins.c \
		./src/basic_function.c \
		./src/path.c \
		./src/list.c \
		./src/builtins_bis.c \
		./src/path_bis.c \
		./src/cd.c \
		./src/my_getnbr.c \
		./src/epure_str.c \
		./src/pointeur_function.c \
		./src/cd_bis.c \
		./src/error.c \
		./src/my_putstr.c \
		./src/redirection.c \
		./src/path_for_remove.c \
		./src/redirection_left.c \
		./src/basic_function_bis.c \
		./src/multiple_execution.c \
		./src/pipe.c \
		./src/exec.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(MAKE) -C ./lib
	 $(CC) $(VAL) $(OBJS) -o $(NAME) -L ./lib -lmy $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) libmy.a
	$(RM) $(NAME)
	cd ./lib && make fclean

re: fclean all

.PHONY: all clean fclean re
