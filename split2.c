/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:33:58 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:32:18 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_in_word(int *count, int in_word)
{
	if (!in_word)
	{
		*count += 1;
		return (1);
	}
	return (0);
}

int	has_quotes(int in_quotes)
{
	if (in_quotes)
		return (0);
	else
		return (1);
}

int	has_delimiter(char *s, char *delimiter)
{
	while (s && *s)
	{
		if (is_quotes(*s, delimiter))
			return (1);
		s++;
	}
	return (0);
}

int	find_idx(char *s, char *delimiter, char *quotes)
{
	int	idx;
	int	in_quotes;

	in_quotes = 0;
	idx = 0;
	while (s && s[idx])
	{
		if (is_quotes(s[idx], quotes) && in_quotes)
			in_quotes = 0;
		else if (is_quotes(s[idx], quotes) && !in_quotes)
			in_quotes = 1;
		if (is_split(s[idx], delimiter) && !in_quotes)
			return (idx);
		idx++;
	}
	return (idx);
}

int	count_words(const char *word, char *delimiter, char *quotes)
{
	int	count;
	int	in_word;
	int	in_quotes;

	count = 0;
	in_word = 0;
	in_quotes = 0;
	while (word && *word)
	{
		if (is_quotes(*word, quotes))
			in_quotes = has_quotes(in_quotes);
		if (!is_split(*word, delimiter) && !in_quotes)
			in_word = is_in_word(&count, in_word);
		else
			in_word = 0;
		word++;
	}
	return (count);
}
