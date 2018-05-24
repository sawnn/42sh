/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** pointeur_function
*/

#include "../../include/my_sh.h"

int	my_call_env(t_mini *mini, node **head)
{
	if ((*head) == NULL)
		my_env(mini, head);
	print_list((*head));
	mini->global = 0;
	return (mini->global);
}

int	my_call_setenv(t_mini *mini, node **head)
{
	if ((*head) == NULL)
		my_env(mini, head);
	if (mini->tab[1] == NULL) {
		print_list((*head));
		return (mini->global);
	}
	if (length_tab(mini->tab) > 3) {
		write(2, "setenv: Too many arguments.\n", 28);
		mini->global = 1;
		return (mini->global);
	}
	if (is_bad_setenv(mini) == 1)
		return (mini->global);
	my_setenv(mini, head);
	mini->global = 0;
	return (mini->global);
}

int	my_call_unsetenv(t_mini *mini, node **head)
{
	if ((*head) == NULL)
		my_env(mini, head);
	if (mini->tab[1] == NULL) {
		write(2, "unsetenv: Too few arguments.\n", 29);
		mini->global = 1;
		return (mini->global);
	}
	my_unsetenv(mini, head);
	mini->global = 0;
	return (mini->global);
}

int	my_call_cd(t_mini *mini, node **head)
{
	if ((*head) == NULL)
		my_env(mini, head);
	mini->global = new_cd(mini, head);
	return (mini->global);
}

int	is_bad_setenv(t_mini *mini)
{
	char	*error = "setenv: Variable name must begin with a letter.\n";
	char	*error2 = "setenv: Variable name must contain alphanumeric";

	if (mini->tab[1][0] >= '0' && mini->tab[1][0] <= '9') {
		write(2, error, my_strlen(error));
		mini->global = 1;
		return (mini->global);
	}
	if (only_alph(mini->tab[1]) == 0) {
		write(2, error2, my_strlen(error2));
		write(2, " characters.\n", 13);
		mini->global = 1;
		return (mini->global);
	}
	return (0);
}
