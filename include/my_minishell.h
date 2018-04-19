/*
** EPITECH PROJECT, 2017
** my_minishell.h
** File description:
** my_minishell.h
*/

#ifndef MY_MINISHELL_H_
#define MY_MINISHELL_H_

#define NOU __attribute__((unused))
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_printf.h"

#define FLAGS_OPEN_BIS S_IRGRP | S_IWGRP | S_IWUSR
#define FLAGS_OPEN O_WRONLY | O_CREAT, S_IRUSR

typedef	struct	s_node {
	char	*str;
	struct	s_node	*next;
} node;

typedef	struct	s_mini {
	char	**tab;
	char	**env;
	char	*buf;
	char	**exit;
	char	**path;
	char	*rpath;
	char	*pwd;
	char	*old;
	char	***cmd;
	char	*savehome;
	char	*patht;
	char	*str;
	int	global;
	node	**head;
	int	j;
	int	min;
	int	cd;
	int	b_exit;
	int	no_path;
} t_mini;

#define	EXEC	execve(mini->rpath, *cmd, mini->env)

char	*get_next_line(int);

/*MY_PUTSTR.C*/
void	my_putstr(char *);
int	my_strlen(char *);

/*MAIN.C*/
int	minishell(t_mini *, node **);
int	length_tab(char **);

/*BASIC_FUNCTION.C*/
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);
char	*remove_slash(char *);
char	*skip_char(char *, int);

/*MY_STR_TO_WORD_ARRAY.C*/
int	num_word(char *);
int	n_cha(char *, int );
char	**my_str_to_word_array(char *);
int	skip_escape(char *, int );

/*MY_STR_TO_WORD_TAB_SEP.C*/
int	alp(char *, char, int);
int	compt_word(char *, char);
int	skip_escape_bis(char *, int);
char	**my_str_to_word_tab_sep(char *, char);

/*BUILTINS.C*/
void	my_env(t_mini *, node **);
void	my_setenv(t_mini *, node **);
void	add_setenv(t_mini *, node **);
void	replace_setenv(t_mini *, node *);
int	check_built(t_mini *, node **);

/*BUILTINS_BIS.C*/
void	my_unsetenv(t_mini *, node **);
int	replace_pwd(char *, node **);
int	replace_oldpwd(char *, node **);
int	save_env(t_mini *, node **);

/*CD.C*/
int	my_cd_path(char *, t_mini *, node **);
int	my_cd_classic(char *, t_mini *, node **);
int	my_cd_minus(t_mini *, node **);
int	my_cd_home(char *, t_mini *, node **);
int	new_cd(t_mini *, node **);

/*CD_BIS.C*/
int	my_cd_path_opendir(t_mini *);
int	my_cd_path_fail_chdir(t_mini *, char *);
int	only_alph(char *);

/*PATH.C*/
void	color(t_mini *);
int	check_path(t_mini *, node **, int);
int	check_remove_path(t_mini *);
int	is_path(t_mini *, node *, int);
int	which_exec(t_mini *);
/*PATH_BIS.C*/
int	is_bin(t_mini *);
void	call_argument(t_mini *, node **);
int	buff_null(t_mini *);
void	is_error_exit(t_mini *);
void	my_prompt(t_mini *, node **);

/*PATH_FOR_REMOVE.C*/
int	check_remove_path_bis(t_mini *, char *);

/*LIST.C*/
node	*add_link(node *, char *);
void	print_list(node *);
int	length_list(node *);
int	delete_node(node **, int );

/*MY_GETNBR.C*/
int	my_getnbr(char *);

/*EPURE_STR.C*/
char	*my_epure_str(char *);

/*POINTEUR_FUNCTION.C*/
int	my_call_env(t_mini *, node **);
int	my_call_setenv(t_mini *, node **);
int	my_call_unsetenv(t_mini *, node **);
int	my_call_cd(t_mini *, node **);
int	is_bad_setenv(t_mini *);

/*ERROR.C*/
void	print_segfault(int, t_mini *);
int	print_errno(t_mini *);

/*REDIRECTION.C*/
int	is_redirection(t_mini *);

/*REDIRECTION_LEFT.C*/
void	put_msg(int, char *);
int	simple_redir_left(t_mini *, int);
int	double_redir_left(t_mini *, int);

/*MULTIPLE_EXECUTION.C*/
int	compt_point(char *);
int	which_call(t_mini *, node **, char *, int);
int	pre_call(t_mini *, node **);
int	send_tab(char ***, t_mini *, node **);

/*PIPE.C*/
int	compt_pipe(char **, t_mini *);
char	***pre_call_pipe(t_mini *);
char	***return_cmd(char **, char ***, int);

/*EXEC.C*/
int	my_exec_pipe(t_mini *, char ***);
int	my_exec(t_mini *);
void	check_error(pid_t, int *, t_mini *);

/*UTILITY.C*/
char	*my_strncat(char *, char *, int);
int	glob(int);
#endif /*MY_MINISHELL_H_*/
