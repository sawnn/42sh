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

int	check_history(char *str)
{
	struct stat st;
	char	*buf = NULL;
	char	**tab = NULL;
	int	i = 0;
	int	ret = 0;
	int	fd = open(".21sh_history", O_CREAT | O_RDONLY, 0666);

	stat(".21sh_history", &st);
	if ((buf = malloc(sizeof(char) * st.st_size + 1)) == NULL)
		return (84);
	ret = read(fd, buf, st.st_size);
	buf[ret] = 0;
	tab = my_str_to_wordtab(buf, '\n');
	i = -1;
	printf("i before %d\n", i);
	while (tab[++i]) {
		printf("tab[%d] = %s\n", i, tab[i]);
	}
	i = len_tab(tab);
	if (str[0] == '!') {
		i = i -2;
		while (tab[i][0] == '!')
			i -= 1;
		printf("%s\n", tab[i]);
		tab[i] ? write(fd, tab[i], my_strlen(tab[i])) : 0;
		tab[i] ? write(fd, "\n", 1) : 0;
		return (1);
	}
	while (tab[--i]) {
		if (my_cmp(str, tab[i]) == 0) {
			close(fd);
			tab[i] ? write(fd, tab[i], my_strlen(tab[i])) : 0;
			tab[i] ? write(fd, "\n", 1) : 0;
			free(tab);
			free(buf);
			return (1);
		}
	}
	free(tab);
	free(buf);
	close(fd);
	return (0);
}

int	main()
{
	char	*s = NULL;
	int	fd = open(".21sh_history", O_CREAT | O_WRONLY, 0666);

	while ("gaspacho andalou") {
		s = gnl(0);
		s ? write(fd, s, my_strlen(s)) : exit(0);
		s ? write(fd, "\n", 1) : 0;
		if (s && s[0] == '!') {
			if (check_history(&s[1]) == 1)
				printf("calling command...\n");
			else
				printf("%s: Event not found.\n", &s[1]);
		}
		free(s);
	}
	return (0);
}
