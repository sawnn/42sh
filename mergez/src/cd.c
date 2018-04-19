/*
** EPITECH PROJECT, 2018
** cd
** File description:
** cd
*/

#include "../include/my.h"
#include "../include/shell.h"
#include <sys/types.h>
#include <dirent.h>

void	cd(char **arg, char **env, int *checky, t_value *sh)
{
	char *str = search_env(env, "HOME=");
	static char *pwd = NULL;
	static char *save = NULL;
	static char *dup;
	save = getcwd(save, 256);
	if (my_strcmp(arg[0], "cd") == 0 && my_strcmp(arg[1], "-") == 0)
		*checky ? my_printf(": No such file or directory.\n") :
			chdir(dup);
	else if (my_strcmp(arg[0], "cd") == 0 && !arg[1]) {
		*checky = 0;
		chdir(str);
	}
	else if (chdir(my_strcat(arg[1], "/")) == 0)
		*checky = 0;
	else {
		my_printf("%s: Not a directory.\n", arg[1]);
		sh->exit = 1;
	}
	pwd = getcwd(pwd, 256);
	dup = my_strdup(save);
}
