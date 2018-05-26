/*
** EPITECH PROJECT, 2018
** word array with word in param
** File description:
** for parsing
*/

#include "../../include/my_sh.h"


/*int	find_word(char *str, char *word)
{
	int	i = 0;
	int	n = 0;

	while (str[i] != '\0') {
		if (strncmp(&str[i], word, strlen(word)) == 0) {
			i += strlen(word);
			n += 1;
		}
		i += 1;
	}
	return (n);
}

char	**word_array_with_word(char *str, char *word)
{
	int	n_word = find_word(str, word);
	char	**tab = malloc(sizeof(char *) * (n_word * n_word + 1) + sizeof(char *));
	int	j = -1;
	int	i = 0;
	int	k = 0;

	while (str[++i] != '\0') {
		if (str[i] == '&') {
			str[i] = '\0';
			printf("&str[%d] = %s\n", k, &str[k]);
			while (str[i] == '&')
				i++;
			str[i] = '\0';
			i  += 1;
//	printf("&str[%d] = %s\n", k, &str[k]);
			k = i + 1;
		}
	}
	if (str[i - 1] != '\0')
		printf("&str[%d] = %s\n", k, &str[k]);
	
	}*/
char	*separate_all(char *str)
{
	char *tab[12] = {";", "&&", "&", "||", "|", ">", "<", ">>", "<<", "(", ")", NULL};
	int i = -1;
	int j = -1;
	char *cmp = strdup(str);
	int tmp = 0;

	printf("%s\n", str);
	while (tab[++i]) {
		while (cmp[++j]) {
			if (j > 0 && strncmp(&cmp[j], tab[i], strlen(tab[i])) == 0 && cmp[j + strlen(tab[i])] != tab[i][0] && cmp[j - 1] != ' ') {
				printf("%c %d %c\n", cmp[j + strlen(tab[i])], j, cmp[j - 1]);
				//if (j > 0 && strncmp(&cmp[j], tab[i], strlen(tab[i])) == 0 && cmp[j - 1] != ' ') {
				str = realloc(str, sizeof(char) * strlen(str) + 2);
				tmp = j;
				str[tmp++] = ' ';
				//str[j + 1] = tab[i][0];
				j -= 1;
				while (cmp[++j])
					str[tmp++] = cmp[j];
				str[tmp] = 0;
				cmp = strdup(str);
				j = -1;
				printf("%s, %d\n", str, i);
			}
			
		}
		j = -1;
	}
	return (cmp);
}


/*void	main(void)
{
	char	*str = strdup("ls && salut && ls && cd");
//	word_array_with_word(str, "&&");
	str = separate_all(str);
	printf("%s\n", str);
	}*/

