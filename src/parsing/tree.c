/*
** EPITECH PROJECT, 2017
** bubblesort.h
** File description:
** a
*/

#include "../../include/tree.h"
#include "../../include/my_sh.h"

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

	if (tab[0] == NULL)
		return (NULL);
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
	char *ope[8] = {";", "&&", "||", "<", "<<", ">", ">>", NULL};

	if (!tab)
		return (-1);
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
		write(1, "? ", 2);
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

int	viewlist(t_tree *list, t_cmd cmd, t_mini *mini)
{
	if (!list)
		return (1);
	//je check si ya une redir
	//si il ya, je vai le dup qui correspon en donnan le right;
	//puis je vais a gauch pr executer
	//puis je remonte sans repassé a droite
	if (list->op && list->op[0] != ';' && is_redir(list->op, list->right->cmd) != 0)
		list->val = 1; 
	if (list->left && list->val != 1) {
		if (viewlist(list->left, cmd, mini))
			return (1);
	}
	if (list->cmd && list->bool == 0) {
		list->bool = 1;
		mini->tab = list->cmd;
		if ((mini->tab = check_dollar(mini->tab, mini)) == NULL)
			return (1);
		list->val= check_cmd(mini, mini->head);
		dup2(cmd.stdout, 1);
		dup2(cmd.stdin, 0);
		if (list->parent)
			list->parent->val = list->val;
	}
//printf("%s\n", list->cmd[0]);
	//else
	//	printf("%s\n", list->op);;
	//printf("%s\n", list->op);
	if (list->op && !(strcmp(list->op, "&&")) && list->left->val == 0) {
		//if (list->right)
		if (viewlist(list->right, cmd, mini))
			return (1);
		
		
	}
	else if (list->op && !(strcmp(list->op, "||")) && list->left->val != 0) {
		if (viewlist(list->right, cmd, mini))
			return (1);
	}
	else if (list->op && check_r(list->op))
		if (viewlist(list->right, cmd, mini))
			return (1);
	return (0);
}

char	**check_null(char **tab)
{
	if (tab == NULL) {
		write(2, "Invalid null command.\n", 22);
		return (NULL);
	}
	return (tab);
}

int	check_ope(char *op)
{
	int i = -1;
	char *tab[8] = {";", "&&", "||", ">", "<", "<<", ">>", NULL};

	if (!op)
		return (0);
	while (tab[++i])
		if (strcmp(tab[i], op) == 0)
			return (0);
	return (1);
		//}
	//return (0);
}

int	put_tree(t_tree **list, t_cmd *cmd, int i)
{
	char **tmp = malloc(sizeof(char *));
	int j = 0;

	if (i == -1) {
		(*list)->cmd = cmd->left;
		return (0);
	}
	(*list)->op = strdup(cmd->left[i]);
	if (cmd->left[i + 1] && check_ope(cmd->left[i + 1])) {
		if (check_r((*list)->op) == 0 && strcmp("||", (*list)->op) && strcmp("&&", (*list)->op)) {
			tmp[0] = strdup(cmd->left[i + 1]);
			tmp[1] = NULL;
			while (check_ope(cmd->left[i + 2])) {
				cmd->left[i] = cmd->left[i + 2];
				i++;
			}
			while (cmd->left[i + 2]) {
				tmp = realloc(tmp, sizeof(char *) * (j + 4));
				tmp[++j] = strdup(cmd->left[i + 2]);
				tmp[j + 1] = NULL;
				i++;
			}
			cmd->right[cmd->r] = tmp;
		}
		else
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
	(*list)->bool = 0;
	(*list)->op = NULL;
	(*list)->left = NULL;
	(*list)->right = NULL;
	(*list)->cmd = NULL;
	cmd->left = move_para(cmd->left);
	if ((i = find_bigger(cmd->left)) == -1) {
		if (((*list)->cmd = check_null(cmd->left)) == NULL)
			return (1);
	}
	//int j = -1;
	//while (cmd->left[++j])
	//	printf("%s\n", cmd->left[j]);
	else
		if (put_tree(list, cmd, i))
			return (1);
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

void	view(t_tree *list)
{
	if (list->left)
		view(list->left);
	if (list->op)
		printf("%s\n", list->op);
	else
		printf("%s\n", list->cmd[0]);
	if (list->right)
		view(list->right);
}

void	tree(char **str, t_mini *mini)
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
	list->bool = 0;
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
			list->bool = 0;
			list->left = NULL;
			list->right = NULL;
			cmd.left = cmd.right[cmd.r - 1];
			cmd.r -= 1;
			//printf("a %s\n", cmd.left[1]);
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
	while (list->parent)
		list = list->parent;
	//printf("%s\n", list->left->cmd[0]);
	//view(list);
	viewlist(list, cmd, mini);
	if (mini->bool == 1) {
		isatty(0) == 1 ? write(1, "exit\n", 5) : 0;
		exit(mini->exitt);
	}
}
