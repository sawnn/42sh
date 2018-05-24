/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../../include/my_sh.h"

int	clear_semicolon(char **str)
{
	char	*new = NULL; int	i = 0;
	int	j = 0; int	count = 0;	char	*tmp = (*str);

	if ((new = malloc(sizeof(char) * my_strlen((tmp) + 1))) == NULL)
		return (-1);
	while (tmp[i] == ';')
		i += 1;
	while (tmp[i] != '\0') {
		new[j++] = tmp[i++];
		if (tmp[i] == ';') {
			is_alph(tmp[i - 1]) == 1 ? new[j] = ' ', j += 1 : 0;
			new[j++] = tmp[i++], new[j++] = ' ';
			count = 1;
		}
		while (tmp[i] && sym(tmp[i], ';') && count == 1)
			i += 1;
		count = 0;
	}
	new[j] = '\0', *str = new;
	return (0);
}
/*
int	clear_ampersand(char **str)
{
	char	*tmp = (*str);
	int	i = 0;
	int	j = 0;
	char	*dest = malloc(sizeof(char) * my_strlen(tmp) + 1);

	while (tmp[i] != '\0') {
		dest[j] = tmp[i];
		printf("dest[%d] = %c - tmp[%d] = %c\n", j, dest[j], i, tmp[i]);
		if (tmp[i] == '&') {
			dest = realloc(dest, j + 4);
			dest[j] = ' ';
			dest[j + 1] = '&';
			dest[j + 2] = ' ';
			printf("\n\ndest[%d] = %c - dest[%d = %c\n\n", j, dest[j], j + 1, dest[j + 1]);

			j += 2;
		}
		printf("\n\ndest[%d] = %c - tmp[%d] = %c\n", j, dest[j], i, tmp[i]);
		i += 1;
		j += 1;
	}
	dest[j] = '\0';
	printf("dest = %s\n", dest);
	return (0);
}
*/
