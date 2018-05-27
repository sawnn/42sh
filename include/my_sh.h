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
#include <glob.h>
#include <fcntl.h>
#include <grp.h>
#include "my_printf.h"
#define FLAGS_OPEN_BIS S_IRGRP | S_IWGRP | S_IWUSR
#define FLAGS_OPEN O_WRONLY | O_CREAT, S_IRUSR
#define CMP my_strcmp(str, mini->tab[i + 1])
#define epur    my_epure_str
#define parent  take_inside_parentheses

typedef	struct	s_node {
	char	*str;
	struct	s_node	*next;
} node;
#include "shell.h"

typedef	struct	s_ifstruct {
	char	**tab;
	struct	s_ifstruct	*next;
} t_ifstruct;

typedef	struct	s_mini {
	char	**tab;
	char	**env;
	char	**b_ali;
	char	*buf;
	char	**exit;
	char	**path;
	char	**repeat;
	char	*rpath;
	char	*pwd;
	char	*fullpath;
	char	*old;
	char	***cmd;
	char	*savehome;
	char	*patht;
	int	cd_d;
	char	*str;
	int	global;
	node	**head;
	int	j;
	int	min;
	char	***alias;
	int	cd;
	int	b_exit;
	int	no_path;
	int	exitt;
	int	bool;
	int	fd;
	t_shell *shell;
	int	wh;
	int	work;
	int	is_exec;
} t_mini;
#include "shell.h"
#include "tree.h"

#define	EXEC	execve(mini->rpath, *cmd, mini->env)

//				LIB				//
/*MAIN.C*/
int	minishell(t_mini *, node **);
int	length_tab(char **);

/*BASIC_FUNCTION.C*/
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);
char	*remove_slash(char *);
char	*skip_char(char *, int);

/*BASIC_FUNCTION_BIS.C*/
void	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	print_tab(char **);
char	*my_strdup(char *, char *);

/*BASIC_FUNCTION_BIS_BIS.C*/
int	length_tab(char **);

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

/*EPURE_STR.C*/
char	*my_epure_str(char *);
char	*get_next_line(int);
//			LIB			//

int	alias_lenght(char **);

//		*BONUS*			//
/*WHITHOUT_ENV.C*/
void	get_simple_env(node **);

//		*MAIN*			//
int	foreach(t_mini *);

//		*BUILTINS*		//

/*WHICH.C*/
int	my_which(t_mini *, node **);

/*WHERE.C*/
int	my_where(t_mini *, node **);

/*REPEAT.C*/
int	repeat(t_mini *, node **);

/*ALIAS.C*/
int	alias_func(t_mini *, node **);
char	**replace_alias(char **, t_mini *);

/*ECHO.C*/
int	my_echo(t_mini *, node**);
int	find_char(char *, char);

/*SPECIAL.C*/
int	special_char(char **);
int	is_special(char **);

/*call_set.c*/
char	**check_dollar(char **, t_mini *);
int	call_set(t_mini *, node **);

/*APLI_CLASSIC_BUILTINS.C*/
void	my_env(t_mini *, node **);
void	add_setenv(t_mini *, node **);
void	replace_setenv(t_mini *, node *);
void	my_setenv(t_mini *, node **);
void	my_unsetenv(t_mini *, node **);

/*CLASSIC_BUILTINS.C*/
int	my_call_env(t_mini *, node **);
int	my_call_setenv(t_mini *, node **);
int	my_call_unsetenv(t_mini *, node **);
int	my_call_cd(t_mini *, node **);
int	is_bad_setenv(t_mini *);

/*ENV_PWD_FUNC.C*/
int	check_built(t_mini *, node **);
int	save_env(t_mini *, node **);
int	replace_pwd(char *, node **);
int	replace_oldpwd(char *, node **);
int	my_exit(t_mini *, node **);

/*CD.C*/
int	my_cd_minus(t_mini *, node **);
int	my_cd_path(char *, t_mini *, node **);
int	my_cd_classic(char *, t_mini *, node **);
int	my_cd_home(char *, t_mini *, node **);
int	new_cd(t_mini *, node **);

/*CD_BIS.C*/
int	my_cd_path_opendir(t_mini *);
int	my_cd_path_fail_chdir(t_mini *, char *);
int	only_alph(char *);

/*CALL_BUILT.C*/
int	call_builtins(int, t_mini *, node **);
int	is_builtins(t_mini *, node **);

/*IF.C*/
void	print_tab(char **);
int	call_func_if(int, char **);
int	check_arg_if(char **);
int	call_if(t_mini *, node **);

/*FUNC_IF.C*/
int	equal_if(char **);
int	diff_if(char **);
int	infer_if(char **);
int	infer_equal_if(char **);
int	superior_if(char **);

/*FUNC_IF_BIS.C*/
int	superior_equal_if(char **);
int	modulo_if(char **);

/*UTILS_IF.C*/
char	*take_inside_parentheses(char *);
int	is_num_for_if(char *);
int	verif_null_tab(char **);
char	*strcat_tab(char **);
char	*skip_word(char *);

/*FINISH_IF.C*/
t_ifstruct	*add_struct(t_ifstruct *, char *);
int	do_if(t_mini *, int, char **);

//		*PATH*			//

/*PATH.C*/
int	check_remove_path_bis(t_mini *, char *);
int	check_remove_path(t_mini *);
int	is_path(t_mini *, node *, int);
int	check_path(t_mini *, node **, int);
int	which_exec(t_mini *);

/*FULL_PATH.C*/
void	strcat_all_path(t_mini *);
void	take_full_path(t_mini *, node **);

//		*PARSING*		//

/*SCRIPT.C*/
int	is_script(char *);

/*GlOBBING.C*/
char	**my_glob(char **);

/*QUOTES.C*/
int	parse_quote(char *);

/*INIBHITOR.C*/
char	*is_inibhitor(char *);

/*CHECK.C*/
char	*check_parentheses(char *);

/*CLEAR.C*/
char	*clear_semicolon(char *);

/*PARSING.C*/
char	*clear_string(char *);
char	*parsor_checker(int, char *);
char	*launch_checker_parsor(t_mini *, char *);

/*UTILS_PARSING.C*/
int	is_alph(char);
int	sym(char, char);

//		*UTILS*			//
/*ERROR.C*/
void	check_error(pid_t, int *, t_mini *);
void	print_segfault(int, t_mini *);
int	print_errno(t_mini *);

/*GESTION_UTILS.C*/
int	is_bin(t_mini *);
void	color(t_mini *);
int	buff_null(t_mini *);
void	is_error_exit(t_mini *);

/*LIST.C*/
node	*add_link(node *, char *);
void	print_list(node *);
int	length_list(node *);
int	delete_node(node **, int);

/*PROMPT.C*/
char	*get_prompt(node *);
void	my_prompt(t_mini *, node **);

/*UTILITY.C*/
void	put_msg(int, char *);
char	*my_strncat(char *, char *, int);
int	globa(int);

//		*EXEC*			//
/*CHECK_CMD.C*/
int	check_cmd(t_mini *, node **);
int	my_exec(t_mini *);

char	**strdup_tab(char **tab);
int	size_tab(char **tab);
int	is_num(char *str);

int	my_script(t_mini *);

#endif /*MY_MINISHELL_H_*/
