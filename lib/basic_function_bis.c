/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Basic_2
*/

#include "../include/my_sh.h"

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int     my_strlen(char *str)
{
	int	i = -1;

	while (str[++i]);
	return (i);
}

int	my_getnbr(char *str)
{
	int	nb = 0;
	int	isneg = 1;
	int	i = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i += 1;
	}
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i += 1;
		}
		else
			return (86);
	}
	return (nb * isneg);
}

void	print_tab(char **tab)
{
	int	i = - 1;

	while (tab[++i] != NULL) {
		my_printf("%s\n", tab[i]);
	}
}

char	*my_strdup(char *dest, char *src)
{
	int	i = -1;

	dest = malloc(sizeof(char) * my_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[++i] != '\0') {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
