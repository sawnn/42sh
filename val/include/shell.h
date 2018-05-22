/*
1;5002;0c** EPITECH PROJECT, 2018
** shell
** File description:
** .h
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	char *op;
	char *value;
	struct s_node *next;
}		t_node;

typedef struct s_shell
{
	t_node *list;
}		t_shell;

int	check_egual_tab(char **);
char	*dollars(char *, t_node *);
char	**my_str_to_wordtab(char *, char);
int	check_egual(char *str);
t_node	*add_link(t_node *, char *, char *);
void	print_list(t_node *list);

#endif /*SHELL_H_*/
