/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:09:19 by luhego            #+#    #+#             */
/*   Updated: 2022/10/24 13:44:40 by luhego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			word++;
		}
	}
	return (word);
}

static int	ft_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_tab_free(char **tab_word)
{
	int	i;

	i = 0;
	while (tab_word[i])
	{
		free(tab_word[i]);
		i++;
	}
	free(tab_word);
}

static void	ft_fill_tab(char **tab_word, const char *s, char c)
{
	int	i;
	int	word_nb;
	int	word_len;

	i = 0;
	word_nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word_len = ft_word_len(&s[i], c) + 1;
			tab_word[word_nb] = ft_calloc(word_len, (sizeof(char)));
			if (tab_word == NULL)
			{
				ft_tab_free(tab_word);
				return ;
			}
			ft_strlcpy(tab_word[word_nb], &s[i], word_len);
			while (s[i] && s[i] != c)
				i++;
		}
		word_nb++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab_word;
	int		word_count;

	if (s == NULL)
		return (0);
	word_count = ft_word_count(s, c);
	tab_word = ft_calloc(word_count + 1, sizeof(char *));
	if (tab_word == NULL)
		return (NULL);
	ft_fill_tab(tab_word, s, c);
	return (tab_word);
}
