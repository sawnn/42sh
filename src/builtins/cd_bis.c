/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** cd
*/

#include "../../include/my_sh.h"

int	my_cd_path_opendir(t_mini *mini)
{
	write(2, mini->tab[1], my_strlen(mini->tab[1]));
	if (errno == EACCES)
		write(2, ": Permission denied.\n", 21);
	else
		write(2, ": Not a directory.\n", 19);
	return (1);
}

int	my_cd_path_fail_chdir(t_mini *mini, char *oldpwd)
{
	mini->pwd = oldpwd;
	write(2, mini->tab[1], my_strlen(mini->tab[1]));
	write(2, ": No such file or directory.\n", 29);
	mini->cd = 1;
	return (1);
}

int	only_alph(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9') &&
			(str[i] < 'a' || str[i] > 'z') &&
			(str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i = i + 1;
	}
	return (1);
}
