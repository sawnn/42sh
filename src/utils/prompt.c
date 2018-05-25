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
	if (isatty(0) == 1)
		my_printf(get_prompt((*head)));
	mini->buf = get_next_line(0);
}
