#include <malloc.h>

size_t _len(char *s)
{
	char	*head;
	size_t	i;

	i = 0;
	head = s;
	while (head && head[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	int 	i;
	int 	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char*)malloc((sizeof(char) * (_len(s1) + _len(s2) + 1)));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *d, char *s, size_t n)
{
	size_t i;

	i = 0;
	if (!d || !s)
		return (0);
	while (s[i] && i < n - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (i);
}