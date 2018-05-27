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
	my_env(mini, head); mini->head = head;
	if (*head == NULL) get_simple_env(head);
	while (1337) {
		my_prompt(mini, head);
		if (mini->buf == NULL) return (buff_null(mini));
		mini->buf = is_inibhitor(mini->buf);
		if ((mini->buf = launch_checker_parsor(mini, mini->buf))== NULL)
			continue;
		if (my_script(mini) == 0)
			continue;
		mini->tab = my_str_to_word_array(mini->buf);
		if (foreach(mini) == 0)
			continue;
		if (mini->tab) {
			mini->b_ali = strdup_tab(mini->tab);
			mini->tab = replace_alias(mini->tab, mini);
		}
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
	mini.alias = NULL;
	mini.b_ali = NULL;
	mini.cd_d = 0; mini.exitt = 0; mini.bool = 0;
	mini.old = NULL;
	mini.str = NULL;
	mini.path = NULL;
	mini.global = 0; mini.min = 0; mini.b_exit = 0; mini.j = 0;
	mini.tab = NULL;
	mini.savehome = NULL;
	mini.head = NULL;
	mini.env = env;
	mini.no_path = 0; mini.cd = 0; mini.fd = 0; mini.wh = 1;
	mini.work = 1; mini.is_exec = 0;
	return (minishell(&mini, &head));
}
