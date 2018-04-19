/*
** EPITECH PROJECT, 2018
** Minishell2
** File description:
** CD
*/

#include "../include/my.h"
#include "../include/gnl.h"
#include "../include/minih.h"

char	*cd_home(char **env)
{
	int	a = -1;

	while (env[++a])
		if (my_strncmp("HOME=", env[a], 5) == 0)
			return (env[a]);
	return (NULL);
}

int	cd_other(use_value *use, char *cd_p, char *actual, char *save)
{
	if (!use->arg[1] || use->arg[1][0] == '~'
		|| (use->arg[1][0] == '-' && use->arg[1][1] == '-'))
		chdir(cd_p);
	else if (my_strcmp(use->arg[0], "cd") == 0
			&& my_strcmp(use->arg[1], "-") == 0) {
		if (actual == NULL && save == NULL) {
			my_printf(": No such file or directory.\n");
			use->exit = 1;
		}
		else
			chdir(save);
	}
	else
		if ((chdir(my_strcat(use->arg[1], "/"))) == -1) {
			my_printf("%s: Not a directory.\n", use->arg[1]);
			use->exit = 1;
		}
}

void	cd_func(use_value *use, char **env)
{
	char	*cd_p = epur_path(cd_home(env));
	static	char	*old_p;
	static	char	*actual;
	static	char	*save;

	old_p = getcwd(old_p, 256);
	cd_other(use, cd_p, actual, save);
	actual = getcwd(actual, 256);
	save = my_strdup(old_p);
}
