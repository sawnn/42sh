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

	while (str[k] != '\0') {
		if (str[k] < 33 || str[k] > 126) {
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
	int a = 0;

	while (pick && bac && ++k < strlen(str)) {
		i = k;
		while (str[k] >= 33 && str[k] <= 126)
			pick[a++] = str[k++];
		if (str[k] < 33 && i != k) {
			pick[a++] = '\0';
			bac[j++] = strdup(pick);
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
	pick = malloc(sizeof(char) * (strlen(str) + 1));
	bac = malloc(sizeof(char*) * (calcule(str) + (sizeof(char*) * 2)));
	if (bac == NULL || pick == NULL)
		return (NULL);
	bac = cut(str, pick, bac, i);
	return (bac);
}
