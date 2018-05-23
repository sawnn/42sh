/*
** EPITECH PROJECT, 2018
** my
** File description:
** gaspacho andalou
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1

typedef struct s_hist {
	char	*hist;
	struct s_hist *next;
} hist_t;

char	*gnl(int);
hist_t	*add_node(hist_t *, char *);
