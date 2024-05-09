/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:25:04 by doji              #+#    #+#             */
/*   Updated: 2024/05/09 17:18:32 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dest, char *source, size_t n)
{
	size_t	idx;

	idx = 0;
	if (!dest || !source)
		return (0);
	if (n == 0)
		return (0);
	while (source[idx] && idx < n - 1)
	{
		dest[idx] = source[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (idx);
}

int	is_split(char c, const char *delimiter)
{
	int	idx;

	idx = 0;
	while (delimiter && delimiter[idx])
	{
		if (c == delimiter[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	is_quotes(char c, const char *quotes)
{
	int	i;

	i = 0;
	while (quotes && quotes[i])
	{
		if (c == quotes[i])
			return (1);
		i++;
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

int	is_in_word(int *count, int in_word)
{
	if (!in_word)
	{
		*count += 1;
		return (1);
	}
	return (0);
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

char	**res_allocation(int size)
{
	char	**res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = NULL;
	return (res);
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
			tmp = (char *)malloc(sizeof(char) * ft_strlen(*words) - 1);
			ft_strlcpy(tmp, *words + 1, ft_strlen(*words) - 1);
			free(*words);
			*words = tmp;
		}
		words++;
	}
	return (head);
}

char	**ft_split(char *words, char *delimiter, char *quotes)
{
	int		i;
	char	**res;

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

int	main(int argc, const char *argv[])
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split("grep 'a b'", " ", "\'\"");
	while (res && res[i])
	{
		printf("%s\n", res[i]);
		if (res[i])
			free(res[i]);
		i++;
	}
	free(res);
}

/*
#include <stdio.h>
int main()
{
	char **res;
	char **temp;

	res = ft_split("grep 'a b' 'c d' 'd' 'f' '", " ", "\'\"");
	temp = res;
	while (*res)
	{
		printf("%s\n", *res++);
	}
	free(temp);
}
*/
