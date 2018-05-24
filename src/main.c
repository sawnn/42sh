/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** main
*/

#include "../include/my_sh.h"

void	sig(int signo)
{
	if (signo == SIGINT)
		if (isatty(0) == 1)
			glob(1);
}

void	check_signals(void)
{
	signal(SIGINT, sig);
	if (glob(-2) == 1)
		glob(0);
}

int	minishell(t_mini *mini, node **head)
{
	my_env(mini, head);
	while (1337) {
		my_prompt(mini, head);
		if (mini->buf == NULL)
			return (buff_null(mini));
		if (launch_checker_parsor(mini, mini->buf) == -1)
			break;
		printf("Fini parsing = %s\n", mini->buf);
		mini->tab = my_str_to_word_array(mini->buf);
		// rendre propre la ligne de commande #theo ok
		// cheeck si ya le nom d'un alias ou dune variable
		//checker si ya des backsticks # valentin
		// checker les guillemet #zack
		//	if (mini->exit[0] != NULL &&
		//	my_strcmp(mini->exit[0], "exit") == 0) {
		//	if (my_exit(mini) == 86) is_error_exit(mini);
		//	else {
		//		isatty(0) == 1 ? write(1, "exit\n", 5): 0;
		//		return (my_exit(mini));
		//	}
//	}
//		if (pre_call(mini, head) == 84)
//			return (mini->global = 84);
		mini->head = head;
		tree(mini->tab, mini);
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
