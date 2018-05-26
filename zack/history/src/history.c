/*
** EPITECH PROJECT, 2018
** history
** File description:
** gaspacho andalou
*/

#include "my.h"
#define my_strcmp strcmp
#define my_strlen strlen
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int	my_cmp(char* s1, char *s2)
{
	int	i = -1;

	while (s1[++i] != 0)
		if (s1[i] != s2[i])
			return (84);
	return (0);
}

int	len_tab(char **tab)
{
	int	i = -1;

	while (tab[++i] != NULL);
	return (i - 1);
}

int	double_hist(char *str, char **tab, int i, int fd)
{
	if (str[0] == '!') {
		i = i -2;
		while (tab[i][0] == '!')
			i -= 1;
		tab[i] ? write(fd, tab[i], my_strlen(tab[i])) : 0;
		tab[i] ? write(fd, "\n", 1) : 0;
		return (1);
	}
	return (0);
}

char	**get_history(int fd)
{
	struct stat st;
	int	ret = 0;
	char	*buf = NULL;
	char **tab = NULL;

	stat(".21sh_history", &st);
	if ((buf = malloc(sizeof(char) * st.st_size + 1)) == NULL)
		return (NULL);
	ret = read(fd, buf, st.st_size);
	buf[ret] = 0;
	tab = my_str_to_wordtab(buf, '\n');
	free(buf);
	return (tab);
}

int	check_history(char *str)
{
	char	**tab = NULL;
	int	i = 0;
	int	fd = open(".21sh_history", O_CREAT | O_RDONLY, 0666);

	tab = get_history(fd);
	i = len_tab(tab);
	if (double_hist(str, tab, i, fd) == 1)
		return (1);
	while (tab[--i]) {
		if (my_cmp(str, tab[i]) == 0) {
			tab[i] ? write(fd, tab[i], my_strlen(tab[i])) : 0;
			tab[i] ? write(fd, "\n", 1) : 0;
			free(tab);
			return (1);
		}
	}
	close(fd);
	free(tab);
	return (0);
}

int	write_history(char *s)
{
	int	fd = open(".21sh_history", O_CREAT | O_WRONLY, 0666);

	s ? write(fd, s, my_strlen(s)) : exit(0);
	s ? write(fd, "\n", 1) : 0;
	if (s && s[0] == '!') {
		if (check_history(&s[1]) == 1)
			printf("calling command...\n");
		else
			printf("%s: Event not found.\n", &s[1]);
	}
	return (0);
}

int	main()
{
	while ("gaspacho andalou")
		write_history(gnl(0));
}
