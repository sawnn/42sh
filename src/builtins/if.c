/*
** EPITECH PROJECT, 2018
** go to if
** File description:
** then else c'est chaud
*/

#include "../../include/my_sh.h"
#include "string.h"
#define epur	my_epure_str
#define	parent	take_inside_parentheses

int	call_func_if(int i, char **tab)
{
	int	(*fptr[8])(char **);

	fptr[0] = equal_if;
	fptr[1] = diff_if;
	fptr[2] = infer_if;
	fptr[3] = infer_equal_if;
	fptr[4] = superior_if;
	fptr[5] = superior_equal_if;
	fptr[6] = modulo_if;
	fptr[7] = NULL;
	return ((*fptr[i])(tab));
}

int	check_arg_if(char **tab)
{
	char	*cmd[8] = {"==", "!=", "<", "<=", ">", ">=", "%", NULL};
	int	i = 0;
	int	ret = 0;

	while (cmd[i] != NULL) {
		if (strcmp(cmd[i], tab[1]) == 0) {
			ret = call_func_if(i, tab);
			if (ret == 1)
				return (1);
			if (ret == -1) {
				put_msg(2, "if: Expression Syntax.\n");
				return (-1);
			}
			if (ret == 0)
				return (0);
		}
		i += 1;
	}
	put_msg(2, "if: Expression Syntax.\n");
	return (-1);
}

int	call_if(t_mini *mini, node **head)
{
	char	*str = parent(epur(skip_word(strcat_tab(mini->tab))));
	char	**tab = my_str_to_word_tab_sep(epur(str), ' '); int	ret = 0;

	if (tab[0] == NULL) { put_msg(2, "if: Too few arguments.\n");
		return (1);
	} if (length_tab(tab) == 1) { put_msg(2, "if: Expression Syntax.\n");
		return (0);
	} if (length_tab(tab) == 2) {
		mini->tab = &tab[1];
		check_cmd(mini, head);
		return (mini->global = 0);
	} if ((ret = check_arg_if(tab) == 1) || ret == 0) {
		if (my_strcmp(tab[3], "then") == 0) {
			if (do_if(mini, ret, &tab[3]) == 1)
				tree(mini->tab, mini);
		} else {
			mini->tab = &tab[3];
			tree(mini->tab, mini);
		} return (mini->global);
	} return (mini->global);
}
