/*
** EPITECH PROJECT, 2017
** listbubble.h
** File description:
** a
*/

#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_sh.h"

#define READ_SIZE 1
typedef struct s_arbre {
	int val;
	char *op;
	char **cmd;
	int bool;
	struct s_arbre *parent;
	struct s_arbre *left;
	struct s_arbre *right;
} t_tree;

typedef struct s_cmd {
	int stdin;
	int stdout;
	char ***right;
	int r;
	char **left;
} t_cmd;

void	tree(char **, t_mini *);

#endif
