/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** Builtins && Instruct
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

int	single_instruct(use_value *use, s_list *list, char **av, char **env)
{
	int	func = 0;

	use->b_arg = strdup_tab(use->arg);
	replace_alias(use->arg, use);
	func = pcp_func(use, list, av, env);
	if (func == 0) {
		(isatty(0)) ? my_puterror("exit\n") : 0;
		return (0);
	}
	func == 1 ? bloczer(use, env): 0;
	func == 2 ? cd_func(use, env): 0;
	func == 3 ? 0 : 0;
	func == 4 ? setenv_func(use, env, list) : 0;
	func == 5 ? unsetenv_func(use, env, list) : 0;
	func == 6 ? print_list(list): 0;
	func == 7 ? alias_func(use->arg, use): 0;
	func == 8 ? unalias_func(use->arg, use): 0;
	return (1);
}

int	or_and_instruct(use_value *use, s_list *list, char **av, char **env)
{
	int	func = 0;
	int	c = -1;

	while (use->multi[++c]){
		use->arg = my_str_to_word_tab(epur_str(use->multi[c]), ' ');
		use->b_arg = strdup_tab(use->arg);
		replace_alias(use->arg, use);
		func = pcp_func(use, list, av, env);
		if (func == 0) {
			(isatty(0)) ? my_puterror("exit\n") : 0;
			return (0);
		}
		func == 1 ? bloczer(use, env): 0;
		func == 2 ? cd_func(use, env): 0;
		func == 3 ? 0 : 0;
		func == 4 ? setenv_func(use, env, list) : 0;
		func == 5 ? unsetenv_func(use, env, list) : 0;
		func == 6 ? print_list(list): 0;
		func == 7 ? alias_func(use->arg, use): 0;
		func == 8 ? unalias_func(use->arg, use): 0;
		if ((use->exit == 1 && use->o_a == '&')
		|| (use->exit == 0 && use->o_a == '|'))
			return (1);
	}
	return (1);
}

int	multi_instruct(use_value *use, s_list *list, char **av, char **env)

{
	int	func = 0;
	int	c = -1;

	while (use->multi[++c]){
		use->arg = my_str_to_word_tab(epur_str(use->multi[c]), ' ');
		use->b_arg = strdup_tab(use->arg);
		replace_alias(use->arg, use);
		func = pcp_func(use, list, av, env);
		if (func == 0) {
			(isatty(0)) ? my_puterror("exit\n") : 0;
			return (0);
		}
		func == 1 ? bloczer(use, env): 0;
		func == 2 ? cd_func(use, env): 0;
		func == 3 ? 0 : 0;
		func == 4 ? setenv_func(use, env, list) : 0;
		func == 5 ? unsetenv_func(use, env, list) : 0;
		func == 6 ? print_list(list): 0;
		func == 7 ? alias_func(use->arg, use): 0;
		func == 8 ? alias_func(use->arg, use): 0;
	}
	return (1);
}

int	builtins_cond(use_value *use, s_list *list, char **av, char **env)
{
	if (use->points == 0)
		return (single_instruct(use, list, av, env));
	else if (use->points > 0 )
		return (multi_instruct(use, list, av, env));
	else
		return (or_and_instruct(use, list, av, env));
}

int	pcp_func(use_value *use, s_list *list, char **av, char **env)
{
	if (!use->arg)
		return (0);
	if (use->arg[0] == NULL)
		return (3);
	else if (my_strcmp("cd", use->arg[use->b]) == 0)
		return (2);
	else if (my_strcmp("exit\0", use->arg[use->b]) == 0)
		return (0);
	else if (my_strcmp("setenv", use->arg[use->b]) == 0)
		return (4);
	else if (my_strcmp("unsetenv", use->arg[use->b]) == 0)
		return (5);
	else if (my_strcmp("env", use->arg[use->b]) == 0)
		return (6);
	else if (my_strcmp("alias\0", use->arg[use->b]) == 0)
		return (7);
	else if (my_strcmp("unalias\0", use->arg[use->b]) == 0)
		return (8);
	return (1);
}

int	bloczer(use_value *use, char **env)
{
	if (access(use->arg[0], F_OK) == 0) {
		direct_path(use, env);
		error_handling(use);
	}
	else
		indirect_path(use, env);
}
