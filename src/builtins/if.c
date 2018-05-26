/*
** EPITECH PROJECT, 2018
** go to if
** File description:
** then else c'est chaud
*/

#include "../../include/my_sh.h"
#include "string.h"
#define epur	my_epure_str

void	print_tab(char **tab)
{
	int	i = -1;

	printf("\n--------TAB------\n");
	while (tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
}

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
			printf("return = %d\n", ret = call_func_if(i, tab));
			if (ret == 1) {
				printf("Jexecute %s avec %s\n", tab[3], cmd[i]);
				return (1);
			}
			if (ret == -1) {
				printf("if: Expression Syntax.\n");
				return (-1);
			}
			if (ret == 0)
				return (0);
		}
		i += 1;
	}
	printf("if: Expression Syntax.\n");
	return (1);
}

int	heja(void)
{
	char	*tmp = "1 <= 2 ls";
	char	*str = epur(take_inside_parentheses(epur(tmp)));
	char	**tab = my_str_to_word_tab_sep(str, ' ');

	print_tab(tab);
	printf("----------------------\n");
	if (tab[0] == NULL) {
		printf("if: Too few arguments.\n");
		return (0);
	}
	//if (verif_null_tab(tab) == -1) {
	//	printf("jsuis null\n");
	//	return (0);
	//}
	if (length_tab(tab) == 1) {
		printf("if: Expression Syntax.\n");
		return (0);
	}
	check_arg_if(tab);
}
