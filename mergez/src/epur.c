/*
** EPITECH PROJECT, 2018
** epur
** File description:
** epur
*/

#include "../include/my.h"
#include "../include/shell.h"

char	*reset_env(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == ' ')
			str[i] = ':';
		i = i + 1;
	}
	return (str);
}

char	*epur_space(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == ':')
			str[i] = ' ';
		i = i + 1;
	}
	return (str);
}

char	*epur_str(char *str)
{
	int i = 0;

	while (str[i] != '=')
		i = i + 1;
	return (epur_space(&str[i] + 1));
}

char	*search_env(char **env, char *str)
{
	int i = 0;

	if (env[0] == NULL)
		return (NULL);
	while (env[i]) {
		if (my_strncmp(str, env[i], 5) == 0)
			return (epur_str(env[i]));
		i = i + 1;
	}
	return (NULL);
}

int	count_path(char **path)
{
	int i = 0;

	while (path[i])
		i = i + 1;
	return (i);
}
