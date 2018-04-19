/*
** EPITECH PROJECT, 2018
** .h
** File description:
** struct
*/

#ifndef MINI_H_
#define MINI_H_

#include <errno.h>

typedef	struct	use_value
{
	char	*epur;
	char	*envi;
	char	**path;
	char	**arg;
	char	**multi;
	int	points;
	char	*t_path;
	pid_t	pid;
	int	a;
	int	b;
	int	clms;
	int	status;
	int	cex;
	int	exit;
} use_value;

typedef	struct	t_list
{
	char	*str;
	struct	t_list	*next;
}	s_list;

void	init_values(use_value *use, char **en);
int	pcp_func(use_value *use, s_list *list, char **av, char **env);
int	builtins_cond(use_value *use, s_list *list, char **av, char **env);
int	bloczer(use_value *use, char **env);

int	my_strncmp(char *dest, char *src, int n);
char	*my_strcat(char *dest, char *src);
char	*my_memset(char *tab, int value, int lenght);

int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *str);

int	count_word(char *envi, char param);
int	count_char(char *envi, char param);
char	**my_str_to_word_tab(char *envi, char param);

void	sign(int signo);
int	check_signals(use_value *use);
char	*epur_str(char *str);
char	*cd_home(char **env);
void	cd_func(use_value *use, char **env);
char	*environement(char **env);
char	*epur_path(char *epur);

void	error_handling(use_value *use);
void	my_puterror(char *str);

void	indirect_path(use_value *use, char **env);
void	direct_path(use_value *use, char **env);

s_list	*get_env(char **zer, s_list *list);

void	print_list(s_list *list);
int	checks(use_value *use);

int	setenv_func(use_value *use, char **env, s_list *list);
int	unsetenv_func(use_value *use, char **env, s_list *list);
s_list	*add_link(s_list *list, char *str);
s_list	*rm_link(s_list *list, char *str);

void	redirections(use_value *use);
#endif	/* MINI_H_ */
