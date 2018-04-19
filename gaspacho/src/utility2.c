/*
** EPITECH PROJECT, 2018
** utility 2
** File description:
** gaspacho andalou
*/

#include "my.h"

char	*my_memset(char *str, int n)
{
	int	i  = -1;

	if ((str = malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	while (++i != '\0')
		str[i] = '\0';
	return (str);
}

char	*my_epure_str(char *str)
{
	char	*tmp;
	int	i = -1;
	int	k = 0;

	if ((tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1))) == NULL)
		return (NULL);
	while ((str[++i] == ' ') || (str[i] == '\t'));
	while (str[i] != '\0') {
		tmp[k++] = str[i++];
		while ((str[i] == ' ') || (str[i] == '\t'))
			i++;
		if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (
			str[i] != '\0')) {
			tmp[k] = ' ';
			k++;
		}
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		my_putchar(str[i]);
}
