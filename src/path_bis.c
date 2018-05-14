/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../include/my_minishell.h"

int	is_bin(t_mini *mini)
{
	if (access(mini->tab[0], F_OK) == 0) {
		mini->rpath = mini->tab[0];
		return (0);
	}
	return (1);
}

void	call_argument(t_mini *mini, node **head)
{
	int	stdin = dup(0);
	int	stdout = dup(1);

	mini->cmd = pre_call_pipe(mini);
	if (is_redirection(mini) == 1)
		return;
	if (check_built(mini, head) >= 0);
	else if (check_path(mini, head, 0) == 0) {
		mini->head = head;
		mini->global = which_exec(mini);
	}
	else if (mini->b_exit != 1) {
		put_msg(2, mini->tab[0]);
		put_msg(2, ": Command not found.\n");
		mini->global = 1;
		mini->b_exit = 0;
	}
	dup2(stdin, 0);
	dup2(stdout, 1);
}

int	buff_null(t_mini *mini)
{
	if (isatty(0) == 1)
		write(1, "exit\n", 5);
	return (mini->global);
}

void	is_error_exit(t_mini *mini)
{
	mini->b_exit = 1;
	mini->global = 1;
}

char	*get_prompt(node *list)
{
	char *prompt = malloc(sizeof(char) * 100);
	int i = -1; int j = 5; int k = 0;
	char getpwd[100];

	while (my_strncmp("USER", list->str, 4) != 0)
		list = list->next;
	while (list->str[j] != '\0')
		prompt[k++] = list->str[j++];
	prompt[k++] = '\0';
	my_strncat(prompt, "@localhost ", 11);
	k = k + 10;
	getcwd(getpwd, 100);
	while (getpwd[++i] != '\0');
	while (getpwd[--i] != '/');
	while (getpwd[++i] != '\0')
		prompt[k++] = getpwd[i];
	prompt[k++] = '\0';
	my_strncat(prompt, "-> ", 3);
	return (prompt);
}

void	my_prompt(t_mini *mini, node **head)
{
	if (isatty(0) == 1)
		my_printf(get_prompt((*head)));
	mini->buf = get_next_line(0);
}
