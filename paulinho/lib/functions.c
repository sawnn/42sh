/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** functions
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

char	*environement(char **env)
{
	int	a = -1;

	while (env[++a])
		if (my_strncmp("PATH=", env[a], 5) == 0)
			return (env[a]);
	return (NULL);
}

char	*epur_path(char *epur)
{
	int	a = 5;
	int	b = 0;
	char	*envi = malloc(sizeof(char) * my_strlen(epur) + 1);

	if (!epur)
		return (0);
	while (epur[a])
		envi[b++] = epur[a++];
	envi[b] = '\0';
	return (envi);
}

int	my_strncmp(char *dest, char *src, int n)
{
	int	a = 0;

	while (dest[a] != '\0' && src[a] != '\0' && a <= n) {
		if (dest[a] > src[a])
			return (1);
		if (dest[a] < src[a])
			return (-1);
		a = a + 1;
		n = n + 1;
	}
	return (0);
}

char	*my_strcat(char *dest, char *src)
{
	char	*tmp;
	int	i = -1;
	int	j = -1;

	if ((tmp = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
		return (NULL);
	while (dest[++i] != '\0')
		tmp[i] = dest[i];
	--i;
	while (src[++j] != '\0')
		tmp[++i] = src[j];
	tmp[++i] = '\0';
	return (tmp);
}

char	*my_memset(char *tab, int value, int lenght)
{
	int	a = 0;

	while (tab && a < lenght) {
		tab[a] = value;
		a = a + 1;
	}
	return (tab);
}
