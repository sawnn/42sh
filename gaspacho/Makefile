##
## EPITECH PROJECT, 2017
## makefile
## File description:
## gaspacho andalou
##

SRC	=	./src/main.c			\
		./src/utility.c			\
		./src/utility2.c		\
		./src/my_str_to_wordtab.c	\
		./src/get_next_line.c		\
		./src/linked_list.c		\
		./src/builtins.c		\
		./src/init.c			\
		./src/call.c			\
		./src/path.c			\
		./src/call_commands.c		\
		./src/my_cd.c			\
		./src/checks.c			\
		./src/env_utils.c		\
		./src/utility3.c		\
		./src/parsing.c			\
		./src/error_sig.c		\
		./src/input.c			\
		./src/red_utils.c		\
		./src/redirections.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -Wextra -I./include -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib_printf
	gcc -o $(NAME) $(OBJ) ./lib_printf/libmy.a

clean:
	rm -f ./src/*.o
	rm -f *~
	rm -f *~
	rm -f ./lib_printf/include/*~
	rm -f ./lib_printf/src/*.o
	rm -f ./lib_printf/src/*~
	rm -f vg*
	rm -f ./src/*~
	rm -f ./include/*~

fclean: clean
	rm -f $(NAME)
	rm -f ./lib_printf/libmy.a

re: fclean all
