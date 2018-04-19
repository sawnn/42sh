/*
** EPITECH PROJECT, 2017
** list
** File description:
** list
*/

#include "../include/my_minishell.h"

node	*add_link(node *head, char *str)
{
	node *elem = malloc(sizeof(node));

	if (elem == NULL)
		return (NULL);
	elem->str = str;
	elem->next = NULL;
	if (head == NULL)
		return (elem);
	else {
		node	*temp = head;
		if (!temp)
			return (NULL);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = elem;
		return (head);
	}
}

void	print_list(node *head)
{
	node	*temp = NULL;

	temp = head;
	while (temp != NULL) {
		my_putstr(temp->str);
		write(1, "\n", 1);
		temp = temp->next;
	}
}

int	length_list(node *head)
{
	int	i = 0;
	node	*pos = head;

	if (head == NULL)
		return (0);
	while (pos != NULL) {
		i = i + 1;
		pos = pos->next;
	}
	return (i);
}

int	delete_node(node **head, int pos)
{
	node	*p = (*head);
	node	*q = NULL;
	int	i = 0;

	if (pos == 0 || pos > length_list((*head))) {
		return (-1);
	}
	if (pos == 1) {
		(*head) = (*head)->next;
		return (0);
	}
	while (++i < pos - 1)
		p = p->next;
	q = p->next;
	p->next = q->next;
	return (0);
}
