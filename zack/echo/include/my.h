/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define READ_SIZE 1

char	*gnl(int);
int	special_char(char **);
int	replace_special(char *);
char	get_special(char);
int	is_special(char **);

int	find_slash(char *);

int	parse_error(char **);
int	is_quote(char *);
