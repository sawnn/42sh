/*
** EPITECH PROJECT, 2018
** my_cd
** File description:
** gaspacho andalou
*/

#include "my.h"

void	cd_minus(char **old_old_pwd, char **pwd)
{
	if (*old_old_pwd == NULL && *pwd == NULL) {
		my_putstr(": No such file or directory.\n");
		call_exit(1);
	}
	chdir(*old_old_pwd);
}

void	cd_part_two(char **tab)
{
	if (chdir(tab[1]) == -1) {
		if (errno == EACCES) {
			write(2, tab[1], my_strlen(tab[1]));
			write(2, ": permission denied\n", 20);
			call_exit(1);
		}
		if (errno == ENOTDIR) {
			write(2, tab[1], my_strlen(tab[1]));
			write(2, ": Not a directory.\n", 19);
			call_exit(1);
		}
	}
}

void	my_cd(char *input, t_list **list)
{
	char		**tab = my_str_to_wordtab(input, ' ');
	static char	*pwd = NULL;
	static char	*old_pwd = NULL;
	static char	*old_old_pwd = NULL;
	char		*st = NULL;

	old_pwd = getcwd(old_pwd, 256);
	tab[1] ? st = my_strdup(tab[1]) : 0;
	if (tab[1] == NULL || st[0] == '~' || (st[0] == '-' && st[1] == '-')) {
		st = get_from_env(*list, "HOME");
		chdir(st);
	} else if (tab[1][0] == '-')
		cd_minus(&old_old_pwd, &pwd);
	else
		cd_part_two(tab);
	pwd = getcwd(pwd, 256);
	old_old_pwd = my_strdup(old_pwd);
}
