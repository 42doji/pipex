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

int	nsplt(char c, const char *dcharset)
{
	int	i;

	i = 0;
	while (dcharset && dcharset[i])
	{
		if (c == dcharset[i])
			return (1);
		i++;
	}
	return (0);
}



int count_words(const char *s, char *charset, char *dcharset)
{
	int	count;
	int	in_word;
	int	in_dc;

	count = 0;
	in_word = 0;
	in_dc = 0;
	while (s && *s)
	{
		if (nsplt(*s, dcharset))
		{
			if (in_dc)
				in_dc = 0;
			else
				in_dc = 1;
		}
		if (!is_split(*s, charset) && !in_dc)
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

int find_idx(char *s, char *charset, char *dcharset)
{
	int i;
	int	in_dc;
	int	in_word;

	in_word = 0;
	in_dc = 0;	
	i = 0;
	while (s && s[i])
	{
		if (nsplt(s[i], dcharset) && in_dc)
			in_dc = 0;
		else if (nsplt(s[i], dcharset) && !in_dc)
			in_dc = 1;
		if (is_split(s[i], charset) && !in_dc)
			return (i);
		i++;
	}
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

char	*word_allocation(char *s, char *charset, char *dcharset)
{
	char	*res;
	int idx;

	idx = 0;
	idx = find_idx(s ,charset, dcharset);
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


char	**ft_split(char *s, char *charset, char *dcharset)
{
	int	i;
	char	**res;

	i = 0;
	res = res_allocation(count_words(s, charset, dcharset));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && is_split(*s, charset))
			s++;
		res[i] = word_allocation(s, charset, dcharset);
		if(!res[i])
		{
			res[i] = NULL;
			break;
		}
		s += find_idx(s, charset, dcharset) + 1;
		i++;
	}
	return (res);
}



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
