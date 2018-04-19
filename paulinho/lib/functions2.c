/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** functions 2
*/

#include "../include/gnl.h"
#include "../include/my.h"
#include "../include/minih.h"

int	my_strlen(char *str)
{
	int	a = -1;

	if (!str)
		return (0);
	while (str[++a]);
	return (a);
}

int	my_strcmp(char *s1, char *s2)
{
	int	a = -1;

	while (s1[++a] || s2[a])
		if (s1[a] != s2[a] || !s1[a] || !s2[a])
			return (1);
	return (0);
}

char	*my_strdup(char *str)
{
	char	*end = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	a = -1;

	while (str[++a])
		end[a] = str[a];
	end[a] = 0;
	return (end);
}

char	*epur_str(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	a = 0;
	int	b = 0;
	if (!str)
		return (NULL);
	while (str[a] && ((str[a] == ' ') || (str[a] == '\t')))
		a = a + 1;
	while (str[a]) {
		tmp[b++] = str[a++];
		while ((str[a] == ' ') || (str[a] == '\t'))
			a = a + 1;
		if (((str[a - 1] == ' ') || (str[a - 1] == '\t'))
			&& str[a]) {
			tmp[b] = ' ';
			b = b + 1;
		}
	}
	tmp[b] = '\0';
	free(str);
	return (tmp);
}

void	my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
