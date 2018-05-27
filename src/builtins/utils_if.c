/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils for if
*/

#include "../../include/my_sh.h"

//en vrai osef mtn non ? //RAJOUTER VALUE DE RETURN POUR PARENTHESES SAVOIR SI YEN A OU PAS
//FAIRE LE trUC QUI APEL TAB[3]

int	is_num_for_if(char *str)
{
	int	i = 0;

	while (str[i]) {
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'))
			i += 1;
		else
			return (-1);
	}
	return (1);
}

int	verif_null_tab(char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2] || !tab[3])
		return (-1);
	return (1);
}

char	*strcat_tab(char **tab)
{
	int	i = -1;
	char	*str = malloc(sizeof(char) * 1);
	str[0] = '\0';

	while (tab[++i] != NULL) {
		str = my_strcat(str, tab[i]);
		str = my_strcat(str, " ");
	}
	return (str);
}

char	*skip_word(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (strncmp(&str[i], "if", 2) == 0)
			return (&str[i + 2]);
		i += 1;
	}
	return ("ok");
}

char	*take_inside_parentheses(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '(')
			str[i] = ' ';
		if (str[i] == ')') {
			str[i] = ' ';
			break;
		}
		i += 1;
	}
	return (str);
}
