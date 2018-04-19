/*
** EPITECH PROJECT, 2018
** ok
** File description:
** ok
*/

#include "../include/my_printf.h"

char	*get_next_line(int fd)
{
	char	buff[1];
	int	i = 0;
	int	j = 0;
	int	k = 0;
	char	*ret;

	if ((ret = malloc(sizeof(char) * 1)) == NULL || fd == -1)
		return (NULL);
	ret[i] = '\0';
	while (read(fd, buff, 1)) {
		if (buff[i] != '\0' && buff[i] != '\n') {
			ret = my_strcat(ret, buff);
			j = j + 1;
		}
		if (buff[i] == '\n') {
			ret[j] = '\0';
			return (ret);
		}
	}
	return (j ? ret : NULL);
}
