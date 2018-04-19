/*
** EPITECH PROJECT, 2017
** .h
** File description:
** minishell
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <fcntl.h>
#include <pwd.h>
#include <langinfo.h>
#include <signal.h>

/* LIBRARY */
int	*my_printf(char const *str, ...);
int	flag_detect(char c);
int	flag_c(va_list ap);
int	flag_modulo(va_list ap);
int	flag_s(va_list ap);
int	flag_i(va_list ap);
int	flag_d(va_list ap);
int	flag_u(va_list ap);
int	flag_b(va_list ap);
int	flag_o(va_list ap);
int	flag_x(va_list ap);
int	flag_big_x(va_list ap);
int	flag_p(va_list ap);
int	flag_big_s(va_list ap);
int	my_putchar(char c);
int     my_putstr(char const *str);
char	**my_str_to_word_tab(char *envi, char param);
void	print_tab(char **tab);
int	size_tab(char **tab);
/* LIBRARY */

#endif /*MY_H_*/
