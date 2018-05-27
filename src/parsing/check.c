/*
** EPITECH PROJECT, 2018
** Check
** File description:
** All check verification
*/

#include "../../include/my_sh.h"

char	*check_parentheses(char *str)
{
	char	*tmp = str; int	i = 0; int	left = 0;
	int	right = 0;
	while (tmp[i] != '\0') {
		(tmp[i] == '(') ? left += 1 : 0;
		(tmp[i] == ')') ? right += 1 : 0;
		if (tmp[i] == ')' && left == 0) {
			put_msg(2, "Too many )'s.\n"); return (NULL);
		}
		if (left == right) {
			left -= 1;
			right -= 1;
		}
		i += 1;
	}
	if (left != right) {
		(left > right) ? (put_msg(2, "Too many ('s.\n")) :
			(put_msg(2, "Too many )'s.\n"));
		return (NULL);
	}
	return (str);
}
