/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** cd
*/

#include "../../include/my_sh.h"

int	my_cd_minus(t_mini *mini, node **head)
{
	char	*oldpwd;

	oldpwd = mini->old;
	mini->old = mini->pwd;
	mini->pwd = oldpwd;
	if (mini->cd == 1 && chdir(mini->pwd) == 0) {
		replace_pwd(mini->pwd, head);
		replace_oldpwd(mini->old, head);
		return (0);
	}
	else if (mini->cd != 1 && chdir(mini->pwd) == -1) {
		write(2, ": No such file or directory.\n", 29);
		mini->min = 1;
	}
	return (1);
}

int	my_cd_path(char *pwd, t_mini *mini, node **head)
{
	char	*oldpwd = malloc(sizeof(char) * 256);

	if ((pwd = malloc(sizeof(char) * 256)) == NULL)
		return (84);
	if (oldpwd == NULL)
		return (84);
	getcwd(oldpwd, 256);
	mini->old = oldpwd;
	if (opendir(mini->tab[1]) != NULL) {
		if (chdir(mini->tab[1]) == 0) {
			getcwd(pwd, 256);
			mini->pwd = pwd;
			replace_pwd(pwd, head);
			replace_oldpwd(oldpwd, head);
			mini->cd = 1;
			return (0);
		}
		return (my_cd_path_fail_chdir(mini, oldpwd));
	}
	return (my_cd_path_opendir(mini));
}

int	my_cd_classic(char *pwd, t_mini *mini, node **head)
{
	char	*oldpwd  = malloc(sizeof(char) * 256);

	if (oldpwd == NULL)
		return (84);
	getcwd(oldpwd, 256);
	mini->old = oldpwd;
	chdir(mini->savehome);
	if ((pwd = malloc(sizeof(char) * 256)) == NULL)
		return (84);
	getcwd(pwd, 256);
	mini->pwd = pwd;
	replace_pwd(pwd, head);
	replace_oldpwd(oldpwd, head);
	mini->cd = 1;
	return (0);
}

int	my_cd_home(char *pwd, t_mini *mini, node **head)
{
	char	*oldpwd = malloc(sizeof(char) * 256);

	if (oldpwd == NULL)
		return (84);
	getcwd(oldpwd, 256);
	mini->old = oldpwd;
	mini->pwd = mini->savehome;
	chdir(mini->savehome);
	if ((pwd = malloc(sizeof(char) * 256)) == NULL)
		return (84);
	getcwd(pwd, 256);
	replace_pwd(pwd, head);
	replace_oldpwd(oldpwd, head);
	mini->cd = 1;
	write(1, "~\n", 2);
	return (0);
}

int	new_cd(t_mini *mini, node **head)
{
	char	*pwd = NULL;

	if (mini->tab[1] == NULL || mini->tab[1][0] == '~' ||
		(mini->tab[1][0] == '-' && mini->tab[1][1] == '-')) {
		return (mini->global = my_cd_classic(pwd, mini, head));
	}
	if (my_strcmp(mini->tab[1], "-") == 0)
		return (mini->global = my_cd_minus(mini, head));
	if (my_strcmp(mini->tab[1], "home") == 0)
		return (mini->global = my_cd_home(pwd, mini, head));
	if (mini->tab[1] != NULL)
		return (mini->global = my_cd_path(pwd, mini, head));
	return (0);
}
