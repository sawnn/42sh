/*
** EPITECH PROJECT, 2018
** finish_if.c
** File description:
** ok
*/

#include "../../include/my_sh.h"

void	tkt(char **tab)
{
	int	i = -1;
	printf("--------------TAB--------------\n");
	while (tab[++i]) {
		printf("tab [%d] = %s\n", i, tab[i]);
	}
	printf("--------------------------------\n");
}

t_ifstruct	*add_struct(t_ifstruct *head, char *str)
{
	t_ifstruct *elem = malloc(sizeof(t_ifstruct));

	if (elem == NULL)
		return (NULL);
	elem->tab = my_str_to_word_tab_sep(str, ' ');
	elem->next = NULL;
	if (head == NULL)
		return (elem);
	else {
		t_ifstruct	*temp = head;
		if (!temp)
			return (NULL);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = elem;
		return (head);
	}
}

int	do_if(t_mini *mini, int ret, char **tab)
{
	char	*s = NULL;
	t_ifstruct	*headif = NULL;
	char	*prompt = "if? ";

	if (tab[1] != NULL) {
		put_msg(2, "if: Improper then.\n");
		mini->global = 1;
		return (0);
	}
	while ("Tu deuh le 42sh") {
		put_msg(0, prompt);
		if ((s = get_next_line(0)) != NULL) {
			if (my_strcmp(s, "else") == 0) prompt = "else? ";
			else if (my_strcmp(s, "endif") == 0) break;
			else headif = add_struct(headif, s);
		}
	}
	ret == 1 ? (mini->tab = headif->tab) : (mini->tab = headif->next->tab);
	return (mini->global = 1);
}
