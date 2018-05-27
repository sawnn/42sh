/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** path
*/

#include "../../include/my_sh.h"

char	*get_prompt(NOU node *list)
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
	int fd = mini->fd;

	if (mini->fd == 0 && isatty(0) == 1)
		my_printf(get_prompt((*head)));
	mini->buf = get_next_line(mini->fd);
	if (mini->buf && parse_quote(mini->buf) == 84) {
		mini->buf[0] = '\0';
		mini->global = 1;
		return;
	}
	if (mini->buf && mini->buf[0] && mini->fd == 0)
		mini->fd = is_script(my_str_to_word_array(mini->buf)[0]);
	if (mini->fd != fd)
		mini->buf = get_next_line(mini->fd);
	if (mini->buf == NULL && mini->fd != 0) {
		mini->fd = 0;
			if (isatty(0) == 1)
				my_printf(get_prompt((*head)));
		mini->buf = get_next_line(mini->fd);
	}
}
