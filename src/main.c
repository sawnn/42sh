/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** main
*/

#include "../include/my_minishell.h"

int	my_exit(t_mini *mini)
{
	if (mini->exit[1] == NULL)
		return (mini->global);
	else if (my_getnbr(mini->exit[1]) == 86 ||
		length_tab(mini->exit) > 2) {
		write(2, "exit: Expression Syntax.\n", 25);
		return (86);
	}
	else
		return (my_getnbr(mini->exit[1]));
}

void	sig(int signo)
{
	if (signo == SIGINT)
		if (isatty(0) == 1)
			glob(1);
			//my_printf("\n\033[1m\033[32m→ 21sh: \033[0");
}

void	check_signals(void)
{
	signal(SIGINT, sig);
	if (glob(-2) == 1)
		//my_printf("A");
	glob(0);
}

int	minishell(t_mini *mini, node **head)
{
	my_env(mini, head);
	while (1337) {
		//check_signals();
		my_prompt(mini, head);
		if (mini->buf == NULL)
			return (buff_null(mini));
		mini->buf = my_epure_str(mini->buf);
		mini->exit = my_str_to_word_array(mini->buf);
		if (mini->exit[0] != NULL &&
			my_strcmp(mini->exit[0], "exit") == 0) {
			if (my_exit(mini) == 86)
				is_error_exit(mini);
			else {
				isatty(0) == 1 ? write(1, "exit\n", 5): 0;
				return (my_exit(mini));
			}
		}
		if (pre_call(mini, head) == 84)
			return (mini->global = 84);
	}
	return (mini->global);
}

int	main(NOU int ac, NOU char **av, char **env)
{
	t_mini	mini;
	node	*head = NULL;

	mini.old = NULL;
	mini.str = NULL;
	mini.path = NULL;
	mini.global = 0;
	mini.min = 0;
	mini.b_exit = 0;
	mini.j = 0;
	mini.tab = NULL;
	mini.savehome = NULL;
	mini.head = NULL;
	mini.env = env;
	mini.no_path = 0;
	mini.cd = 0;
	return (minishell(&mini, &head));
}
