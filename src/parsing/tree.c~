/*
** EPITECH PROJECT, 2017
** bubblesort.h
** File description:
** a
*/

#include "../../include/tree.h"

int	go_end(char **tab)
{
	int j = -1;

	while (tab[++j]);
	while (strcmp(tab[--j], ")"));
	return (j);
}

char	**move_para(char **tab)
{
	int i = -1;
	int j = 0;
	int cmp = 0;
	int tmp = 0;

	while (tab[++i]);
	while (cmp == 0) {
		if (strcmp(tab[i - 1], ")") == 0 && strcmp(tab[j], "(") == 0) {
			tab[i - 1] = NULL;
			i--;
			j++;
			tmp = 1;
		}
		else
			cmp = 1;
	}
	//return (&tab[i]);
	if (tmp == 1)
		return (&tab[j]);
	return (tab);
}

int	find_bigger(char **tab)
{
	int i = -1;
	int j = -1;
	char *ope[6] = {";", "&&", "||", ">", "<", NULL};

	while (ope[++i]) {
		while (tab[++j]) {
			if (strcmp(tab[j], "(") == 0)
				j = go_end(tab);
			if (i != 1 && i != 2 && strcmp(tab[j], ope[i]) == 0)
				return (j);
			if ((i == 1 && (strcmp(tab[j], ope[i]) == 0
			|| strcmp(tab[j], ope[i + 1]) == 0)))
				return (j);
		}
		j = -1;
	}
	return (-1);
}

int	put_in(char *name)
{
	int fd = open(name, O_RDONLY);

	if (fd == -1) {
		write(2, name, strlen(name));
		write(2, ": No such file or directory.\n", 29);
		return (1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	put_out(char *name)
{
	int fd = open(name, 577, 432);

	dup2(fd, 1);
        close(fd);
	return (0);
}

int	put_double_out(char *name)
{
	int fd = open(name, 577, 432);

	dup2(fd, 1);
        close(fd);
	return (0);
}

int	put_double_in(char *name)
{
	int fd = open(".test", 577, 432);
	char *str;

	do {
		if (str)
			free(str);
		write(1, "? ", 1);
		if ((strcmp((str = get_next_line(0)), name) != 0)) {
			write(fd, str, strlen(str));
			write(fd, "\n", 1);
		}
	} while (str && strcmp(str, name) != 0);
	put_in(".test");
	return (0);
}

int	is_redir(char *op, char **name)
{
	if (!(strcmp(op, "<")))
		return (put_in(name[0]));
	if (!(strcmp(op, ">")))
		return (put_out(name[0]));
	if (!(strcmp(op, "<<")))
		return (put_double_in(name[0]));
	if (!(strcmp(op, ">>")))
		return (put_double_out(name[0]));
	return (0);
	    
}

int	check_r(char *op)
{
	if (strcmp(op, "||") && (strcmp(op, "&&"))
	&& strcmp(op, "<") && (strcmp(op, ">")))
		if (strcmp(op, ">>") && (strcmp(op, "<<")))
			return (1);
	return (0);
}

void	viewlist(t_tree *list, t_cmd cmd)
{
	if (!list)
		return;
	//je check si ya une redir
	//si il ya, je vai le dup qui correspon en donnan le right;
	//puis je vais a gauch pr executer
	//puis je remonte sans repassé a droite
	if (list->op && list->op[0] != ';' && is_redir(list->op, list->right->cmd) != 0)
		list->val = 1; 
	if (list->left && list->val != 1)
		viewlist(list->left, cmd);
	if (list->cmd) {
		list->val= system(list->cmd[0]);
		dup2(cmd.stdout, 1);
		dup2(cmd.stdin, 0);
		if (list->parent)
			list->parent->val = list->val;
	}
//printf("%s\n", list->cmd[0]);
	//else
	//	printf("%s\n", list->op);;
	//printf("%s\n", list->op);
	if (list->op && !(strcmp(list->op, "&&")) && list->left->val == 0)
		//if (list->right)
		viewlist(list->right, cmd);
	else if (list->op && !(strcmp(list->op, "||")) && list->left->val != 0)
		viewlist(list->right, cmd);
	else if (list->op && check_r(list->op))
		viewlist(list->right, cmd);
}

int	put_tree(t_tree **list, t_cmd *cmd, int i)
{
	
	//while (list->left)
	//	put_tree(list->left, cmd, i);
	if (i == -1) {
		(*list)->cmd = cmd->left;
		return (0);
	}
	(*list)->op = strdup(cmd->left[i]);
	if (cmd->left[i + 1]) {
		cmd->right[cmd->r] = &cmd->left[i + 1];
		cmd->right[cmd->r] = move_para(cmd->right[cmd->r]);
		cmd->r += 1;
		cmd->right = realloc(cmd->right, sizeof(char **) * (cmd->r + 1));
	} else if (check_r(cmd->left[i]) == 0 && cmd->left[i + 1] == NULL) {
		if (strcmp(cmd->left[i], "||") && (strcmp(cmd->left[i], "&&")))
			write(2, "Missing name for redirect\n", 26);
		else
			write(2, "Invalid null command.\n", 22);	
		return (1);
	}
	cmd->left[i] = NULL;
	(*list)->left = malloc(sizeof(t_tree));
	(*list)->left->parent = *list;
	*list = (*list)->left;
	(*list)->val = 0;
	(*list)->op = NULL;
	(*list)->left = NULL;
	(*list)->right = NULL;
	(*list)->cmd = NULL;
	cmd->left = move_para(cmd->left);
	if ((i = find_bigger(cmd->left)) == -1)
		(*list)->cmd = cmd->left;
	//int j = -1;
	//while (cmd->left[++j])
	//	printf("%s\n", cmd->left[j]);
	else
		put_tree(list, cmd, i);
	return (0);
	//*list = (*list)->parent;
	//while ((*list)->parent)
	//	*list = (*list)->parent;
		//if (list->right)
		//put_tree(list->right, cmd, i);
}

/*void	add_to_list(int data, t_tree **list)
{
	t_tree *tmp = *list;
	t_tree *tmp2 = NULL;
	t_tree *element = malloc(sizeof(t_tree));

	if (element == NULL)
		exit(0);
	//element->data = data;
	element->left = NULL;
	element->right = NULL;
	element->parent = NULL;
	while (tmp != NULL) {
		tmp2 = tmp;
			if (data > tmp->data) {
			tmp = tmp->right;
			(!tmp) ? (tmp2->right = element)
			&& (tmp2->right->parent = tmp2) : 0;
		} else {
			tmp = tmp->left;
			(!tmp) ? (tmp2->left = element)
			&& (tmp2->left->parent = tmp2) : 0;
		}
		if (!tmp) return;
	}
	*list = element;
	}*/

void	fill_cmd(t_cmd *cmd, char **str)
{
	cmd->stdin = dup(0);
	cmd->stdout = dup(1);
	cmd->right = malloc(sizeof(char **));
	cmd->right[0] = NULL;
	cmd->r = 0;
	cmd->left = str;
}

void	tree(char **str)
{
	
	int i;
	t_cmd cmd;
	t_tree *list = malloc(sizeof(t_tree));

	str = move_para(str);
	i = find_bigger(str);
	fill_cmd(&cmd, str);
	list->cmd = NULL;
	list->op = NULL;
	list->val = 0;
	list->left = NULL;
	list->right = NULL;
	list->parent = NULL;
	do {
		cmd.right[cmd.r] = NULL;
		
		if (put_tree(&list, &cmd, i))
			return;
		do {
			if (list->parent)
				list = list->parent;
		} while (list->parent && list->right != NULL);
		
		if (list->right == NULL && cmd.right[0] != NULL) {
			list->right = malloc(sizeof(t_tree));
			list->right->parent = list;
			list = list->right;
			list->val = 0;
			list->cmd = NULL;
			list->op = NULL;
			list->left = NULL;
			list->right = NULL;
			cmd.left = cmd.right[cmd.r - 1];
			cmd.r -= 1;
			i = find_bigger(cmd.left);
		}
		
		
	} while (cmd.right[0] != NULL);
	
	//add_to_list(
	
	/*while (list->left)
		list = list->left;
	while (list->parent) {
		printf("%d\n", list->data);
		if (list->right) {
			list = list->right;
			printf("%d\n", list->data);
		}
		list = list->parent;
		}*/
	viewlist(list, cmd);
}
