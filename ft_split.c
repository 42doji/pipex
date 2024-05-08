#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

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


int	has_charset(char *s, char *charset)
{
	while (*s)
	{
		if (nsplt(*s, charset))
			return (1);
		s++;
	}
	return (0);
}

char	*_replace(char *s)
{
	char	*head;
	int	i;

	i = 0;
	head = s;
	while (s && s[i])
	{
		if (nsplt(s[i], "\'\""))
		{
			s[i] = '\0';
		}
		i++;
	}
	return (head);
}

char	**ft_split_v2(char **s)
{
	char	*tmp;
	char	**head;
	head = s;
	while (*s)
	{
		if (has_charset(*s, "\'\""))
		{
			*s = *s + 1;
			*s = _replace(*s);
		}
		s++;
	}
	return (head);
}

char	*dup_args(char *s)
{
	char	*res;
	int	i;
	
	i = 0;
	res = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *s, char *charset, char *dcharset)
{
	int	i;
	char	**res;
	char	*args;

	args = dup_args(s);
	i = 0;
	res = res_allocation(count_words(args, charset, dcharset));
	if (!res)
		return (NULL);
	while (*args)
	{
		while (*args && is_split(*args, charset))
			args++;
		res[i] = word_allocation(args, charset, dcharset);
		if(!res[i])
		{
			res[i] = NULL;
			break;
		}
		args += find_idx(args, charset, dcharset) + 1;
		i++;
	}
	return (ft_split_v2(res));
}

#include <stdio.h>

int	main(int argc,const char *argv[])
{
	char **res;

	printf("%s\n", argv[1]);
	res = ft_split((char *)argv[1], " ", "\'\"");
	while (*res)
	{
		printf("%s\n", *res++); 
	}	
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
