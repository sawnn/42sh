/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char	*my_strcat(char *dest, char const *src)
{
	int	i = -1;
	int	j = -1;
	int	z = 0;
	int	size = my_strlen(dest) + my_strlen(src) + sizeof(char);
	char	*cat;

	if (dest == NULL)
		return (NULL);
	if ((cat = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (dest[++i])
		cat[z++] = dest[i];
	while (src[++j])
		cat[z++] = src[j];
	cat[z] = '\0';
	return (cat);
}
