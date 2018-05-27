/*
** EPITECH PROJECT, 2018
** magic
** File description:
** quotes
*/

#include "../include/shell.h"

int	inside_quotes(char *str)
{
	int nb = 0;
	int i = 0;

	while (str[i] && str[i] != '`') {
		nb += 1;
		i += 1;
	}
	printf("nb = %d\n", nb);
	return (nb);
}

char	*cpy(char *str, int nb)
{
	int i = 0;
	char *tmp = NULL;

	if ((tmp = malloc(sizeof(char) * nb + 1)) == NULL)
		return (NULL);
	while (str[i] && str[i] != '`') {
		tmp[i] = str[i];
		i += 1;
	}
	return (tmp);
}

void	magic_quotes(char *str)
{
	int i = 0;
	int nb = 0;
	char *tmp = NULL;

	while (str[i]) {
		if (str[i] == '`') {
			nb = inside_quotes(&str[i + 1]);
			tmp = cpy(&str[i + 1], nb);
			printf("tmp = %s\n", tmp);
			i += nb + 1;
		}
		i += 1;
	}
}

void	print_tab(char **tab)
{
	int i = 0;

	while (tab[i]) {
		printf("[%s]\n", tab[i]);
		i += 1;
	}
}

int	main(int ac, char **av)
{
	char *str = "ls `ls -la` ls `wdsadhoami`wfewqt4eqg s";
	

	
	//magic_quotes(str);
}
