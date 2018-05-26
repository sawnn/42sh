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
			globa(1);
}

void	check_signals(void)
{
	signal(SIGINT, sig);
	if (globa(-2) == 1)
		globa(0);
}

int	minishell(t_mini *mini, node **head)
{
	my_env(mini, head);
	if (*head == NULL)
		get_simple_env(head);
	while (1337) {
		my_prompt(mini, head);
		if (mini->buf == NULL)
			return (buff_null(mini));
		mini->buf = is_inibhitor(mini->buf);
		if (parse_quote(mini->buf) == 84) {
			mini->buf[0] = '\0';
			mini->global = 1;
		}
		if ((mini->buf = launch_checker_parsor(mini, mini->buf)) == NULL)
			continue;
		mini->tab = my_str_to_word_array(mini->buf);
		mini->tab = check_dollar(mini->tab, mini);
		// rendre propre la ligne de commande #theo ok
		// cheeck si ya le nom d'un alias ou dune variable
		//checker si ya des backsticks # valentin
		// checker les guillemet #zack

		mini->head = head;
		save_env(mini, head);
		if (mini->tab && mini->tab[0])
			tree(mini->tab, mini);
	}
	return (mini->global);
}

int	main(NOU int ac, NOU char **av, char **env)
{
	t_mini	mini;
	node	*head = NULL;

	if ((mini.shell = malloc(sizeof(t_shell))) == NULL)
		return (84);
	mini.exitt = 0;
	mini.bool = 0;
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
	mini.fd = 0;
	return (minishell(&mini, &head));
}
