/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** a
*/

#include "../include/my_sh.h"

int	calcule(char const *str)
{
	int i = 1;
	int k = 0;
	int tmp = 0;

	while (str[k] != '\0') {
		if (str[k] == '"')
			tmp++;
		if ((str[k] == '&' || str[k] == '|' && str[k] == '>' || str[k] == '<' || str[k] == '(' || str[k] == ')' || str[k] == ';' ) && !(tmp % 2))
				i++;
		if ((str[k] < 33 || str[k] > 126) && !(tmp % 2)) {
			i++;
		
				
		}
		k++;
	}
	return (i);
}

char	**cut(char *str, char *pick, char **bac, int i)
{
	int k = -1;
	int j = 0;
	int cmp = 0;
	int a = 0;
	char c = 0;
	int tmp = 0;

	while (pick && bac && ++k < my_strlen(str)) {
		i = k;
		
		while ((str[k] != '&' && str[k] != '|' && str[k] != '>' && str[k] != '<' && str[k] != '(' && str[k] != ')' && str[k] != ';' && str[k] >= 33 && str[k] <= 126) || (tmp % 2)) {
			if (str[k] == '"') {
				tmp++;
				k++;
			} else
				pick[a++] = str[k++];
		}
		if ((str[k] == '&' || str[k] == '|' || str[k] == '>' || str[k] == '<' || str[k] == '(' || str[k] == ')' || str[k] == ';' )) {
			c = str[k];
			if (str[k] == '(' || str[k] == ')' || i != k) {
				if (i == k) {
					pick[a++] = c;
					
				} else
					cmp = 1;
				pick[a++] = 0;
				bac[j++] = strdup(pick);
			}
			a = 0;
		}
		while (str[k] == c && str[k] != '(' && str[k] != ')')
			pick[a++] = str[k++];
			
	
		if (str[k] != '(' && str[k] != ')' && ((str[k] < 33 && i != k) || str[k - 1] == c)) {
			pick[a++] = '\0';
			bac[j++] = strdup(pick);
			if (c) {
				
				k--;
				c = 0;
			}
		}
		if (cmp == 1) {
			k--;
			cmp = 0;
		}
		a = 0;
	}
	bac[j] = NULL;
	return (bac);
}

char	**my_str_to_word_array(char *str)
{
	char *pick = NULL;
	char **bac = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	pick = malloc(sizeof(char) * (my_strlen(str) + 1));
	bac = malloc(sizeof(char*) * (calcule(str) + (sizeof(char*) * 2)));
	if (bac == NULL || pick == NULL)
		return (NULL);
	bac = cut(str, pick, bac, i);
	return (bac);
}
