/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:44 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:30:49 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**clean_all(char **words, int i)
{
	while (i >= 0)
	{
		if (words && words[i])
			free(words[i]);
		i--;
	}
	if (words && *words)
		free(words);
	return (NULL);
}

char	**quotes_terminator(char **words)
{
	char	**head;
	char	*tmp;

	if (!words)
		return (NULL);
	head = words;
	while (words && *words)
	{
		if (has_delimiter(*words, "\'\""))
		{
			tmp = (char *)malloc(sizeof(char) * len(*words) - 1);
			ft_strlcpy(tmp, *words + 1, len(*words) - 1);
			free(*words);
			*words = tmp;
		}
		words++;
	}
	return (head);
}

char	*word_allocation(char *s, char *delimiter, char *quotes)
{
	char	*res;
	int		idx;

	if (!s)
		return (NULL);
	idx = 0;
	idx = find_idx(s, delimiter, quotes);
	if (idx)
	{
		res = (char *)malloc(sizeof(char) * (idx + 1));
		if (!res)
			return (NULL);
		ft_strlcpy(res, s, idx + 1);
	}
	else
		return (NULL);
	return (res);
}

char	**res_allocation(int size)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = NULL;
	return (res);
}

char	**ft_split(char *words, char *delimiter, char *quotes)
{
	char	**res;
	int		i;

	i = 0;
	res = res_allocation(count_words(words, delimiter, quotes));
	if (!res)
		return (NULL);
	while (*words)
	{
		while (*words && is_split(*words, delimiter))
			words++;
		res[i] = word_allocation(words, delimiter, quotes);
		if (!res[i])
			return (clean_all(res, i - 1));
		words += find_idx(words, delimiter, quotes);
		i++;
	}
	return (quotes_terminator(res));
}
