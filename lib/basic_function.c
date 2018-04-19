/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Basic_1
*/

#include "../include/my_minishell.h"

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i = i + 1;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
	int	i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0') {
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i = i + 1;
	}
	return (0);
}

char	*my_strcat(char *str, char *str2)
{
	char	*tmp = NULL;
	int	a = 0;
	int	b = 0;
	int	c = my_strlen(str) + my_strlen(str2) + 2;

	if ((tmp = malloc(sizeof(char) * c)) != NULL) {
		while (str[a] != '\0') {
			tmp[a] = str[a];
			a++;
		}
		while (str2[b] != '\0') {
			tmp[a] = str2[b];
			a++;
			b++;
		}
		tmp[a] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	*remove_slash(char *str)
{
	int	i = 0;
	int	j = 0;
	int	length = 0;
	char	*s2 = NULL;

	while (str[i] != '\0') {
		if (str[i] == '/')
			j = i;
		i = i + 1;
	}
	length = j;
	if ((s2 = malloc(sizeof(char) * length + sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i != j) {
		s2[i] = str[i];
		i = i + 1;
	}
	s2[i + 1] = '\0';
	return (s2);
}

char	*skip_char(char *str, int j)
{
	int	i = 0;
	char	*s2 = str;

	while (i != j) {
		i = i + 1;
	}
	return (&s2[i]);
}
