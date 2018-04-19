/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#ifndef MY_H_
#define MY_H_

#define UNU __attribute__((unused))
#define READ_SIZE 1

typedef struct s_list {
	char	*str;
	struct s_list *next;
} t_list;

typedef struct s_shell {
	char	glob;
	char	*input;
	char	*path;
	char	**env;
	char	**tab;
	int	pipefd[2];
	t_list	*my_env;
} t_shell;

int	my_printf(char *str, ...);

/*MAIN.C*/
int	find_command(t_shell *);

/*UTILITY.C*/
int	my_strlen(char *);
char	*my_strdup(char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);

/*UTILITY2.C*/
char	*my_memset(char *, int);
char	*my_epure_str(char *);
void	my_putchar(char);
void	my_putstr(char *);

/*GET_NEXT_LINE.C*/
char	*get_next_line(int);

/*LINKED_LIST.C*/
t_list	*add_node(t_list *, char *);
void	print_list(t_list *);

/*MY_STR_TO_WORDTAB.C*/
int	count_words(char *, char);
int	count_l(char *, char);
void	my_strncpy(char *, char *, int);
int	count_tabs(char **);
char	**my_str_to_wordtab(char *, char);

/*BUILTINS.C*/
void	print_env(char *, t_list **);
void	my_setenv(char *, t_list **);
void	my_unsetenv(char *, t_list **);
void	my_cd(char *, t_list **);
void	my_exit(char *, t_list **);

/*INIT.C*/
char	**tab_command(void);

/*CALL.C*/
int	call_exit(int);
int	keep_path(int);
void	call_builtin(int, t_shell *);

/*PATH.C*/
char    *get_path(char *, char *);
char    *find_path(t_shell *, int);

/*CALL_COMMANDS.C*/
void	handle_errno(char **);
void	command_not_found(char **, int);
int	call_command(t_shell *);

/*MY_CD.C*/
void    my_cd(char *, t_list **);

/*CHECKS.C*/
int	check_name(char **);

/*ENV_UTILS.C*/
void	setenv_exist(char **, t_list *, t_list **, t_list *);
void	setenv_new_node(char **, t_list **, t_list **, t_list *);
t_list	*fill_env(char **, t_shell *);
char	*get_from_env(t_list *,  char *);

/*UTILITY3.C*/
int	my_getnbr(char *);

/*PARSING.C*/
char	**semicolon(char *);

/*ERROR_SIG.C*/
void	check_segfault(int);

/*INPUT.C*/
void	handle_input(t_shell *);

/*RED_UTILS.C*/
void	apply_redirection(int, t_shell *, char *);
int	is_redirection(char *);
int	redirections(t_shell *);

/*REDIRECTIONS.C*/
void	simple_right(t_shell *, char *);
void	simple_left(t_shell *, char *);
void	double_right(t_shell *, char *);
void	double_left(t_shell *, char *);

/*PIPE.C*/
int	find_pipe(char **);
int	count_pipe(char **);
int	my_pipe(t_shell *);

#endif
