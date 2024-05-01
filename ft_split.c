#include "pipex.h"

int	is_split(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset && charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int count_words(const char *s, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (s && *s)
	{
		if (!is_split(*s, charset))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

int find_idx(char *s, char *charset)
{
	int i;

	i = 0;
	while (s && s[i] && !is_split(s[i], charset))
		i++;
	return (i);
}

char **res_allocation(int size)
{
	char	**res;

	res = (char**)malloc(sizeof(char*) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	return (res);
}

char	*word_allocation(char *s, char *charset)
{
	char	*res;
	int idx;

	idx = 0;
	idx = find_idx(s ,charset);
	if (idx)
		res = (char *)malloc(sizeof(char) * (idx + 1));
	else
		return (NULL);
	ft_strlcpy(res, s, idx + 1);
	return (res);
}

char** clean_all(char **string, int i)
{
	while (i >= 0)
		free(string[i--]);
	return (NULL);
}


char	**ft_split(char *s, char *charset)
{
	int	i;
	char	**res;

	i = 0;
	res = res_allocation(count_words(s, charset));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && is_split(*s, charset))
			s++;

		res[i] = word_allocation(s, charset);
		if(!res[i])
			return (clean_all(res, i));
		s += find_idx(s, charset) + 1;
		i++;
	}
	return (res);
}
//
//#include <stdio.h>
//int main()
//{
//	char **res;
//	char **temp;
//
//	res = ft_split("a a a asdf xczv . , adsfasdf, asdf. t, t,t.t.t tttt     t.", " ,.");
//	temp = res;
//	while (*res)
//	{
//		printf("%s\n", *res++);
//	}
//	free(temp);
//}