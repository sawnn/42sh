/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** gaspacho andalou
*/

#include "my.h"

void	gnl_memset(char buf[READ_SIZE + 1], char c, int n)
{
	int	i = -1;

	while (++i != n)
		buf[i] = c;
	buf[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buf[READ_SIZE + 1];
	static int	i = 0;
	char		*tmp = NULL;
	int		j = 0;
	int		k = 0;

	if ((tmp = malloc(sizeof(char) * 4096)) == NULL)
		return (NULL);
	while ("Gaspacho andalou") {
		if (i == 0) {
			gnl_memset(buf, '\0', READ_SIZE + 1);
			k = read(fd, buf, READ_SIZE);
		}
		if (i == 0 && (((k == 0 && i) || (k == 0 && !i)) || k < 0))
			return (k == 0 && i ? buf : NULL);
		while (buf[i] && buf[i] != '\n' && (tmp[j++] = buf[i++]));
		if (buf[i++] == '\n' && !(tmp[j] = '\0'))
			return (tmp);
		i = 0;
	}
}
