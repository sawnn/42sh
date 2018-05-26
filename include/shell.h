/*
** EPITECH PROJECT, 2018
** shell
** File description:
** .h
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_set
{
	char *op;
	char *value;
	struct s_set *next;
}		t_set;

typedef struct s_shell
{
	t_set *list;
}		t_shell;
#include "my_sh.h"

void	fct_set(char **, t_shell*);
int	check_egual_tab(char **);
char	**my_str_to_wordtab(char *, char);
char	*dollars(char *, t_set *, node **);
int	check_egual(char *str);
t_set	*addd_link(t_set *, char *, char *);

#endif /*SHELL_H_*/
