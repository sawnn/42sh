/*
** EPITECH PROJECT, 2018
** .h
** File description:
** .h
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_env
{
	char *str;
	struct s_env *next;
}		t_env;

typedef struct s_value
{
	t_env	*env;
	char	**env_char;
	char *str;
	char *file;
	char *tmp;
	char **command;
	char **path;
	char **arg;
	char *strcat;
	pid_t child_pid;
	int exit;
	int i;
	int status;
	int check;
	int sign;
	int prompt;
}		t_value;

void	go_to_pipe(t_value *, char **);
void	my_prompt(char *str);
void	catch_c(int sign);
void	permission_denied(t_value *sh, char **env);
void	error(t_value *sh);
void	move_env(t_value *sh, char **env);
void	builtins_env(t_value *sh, char **env, int *checky, int *path);
int	builtins_exit(t_value *sh, char **env, int *path);
void	print_list(t_env *);
int	my_setenv(t_value *sh, char **arg);
int	my_unsetenv(t_value *sh, char **arg);
t_env	*add_link(t_env *list, char *str);
void	printf_list(t_env *list);
int	count_path(char **path);
char	*search_env(char **env, char *str);
char	*epur_str(char *str);
char	*epur_space(char *str);
char	*reset_env(char *str);
char	*search_env(char **env, char *str);
void	cd(char **arg, char **env, int *checky, t_value *);
int	pars_command(t_value *);
int	check_semicolons(t_value *, char **, int *, int *);
int	nb_semicolons(t_value *);
int	my_shell(t_value *sh, char **env, int *checky, int *path);
int	count_pipe(char **, t_value *);
void	pipe_fonction(char ***, t_value *, char **);
void	triple_tab(char **, int, t_value *, char **);
char	*get_next_line(int fd);
void	pipe_fonction(char ***, t_value *, char **);
void	check_envi(t_value *, char **, char *);

#endif /*SHELL_H_*/
