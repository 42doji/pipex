/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:34:24 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:59:34 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	str_len(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	int		i;

	s1_len = str_len((char *)s1);
	s2_len = str_len((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*search_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, ENV_PATH, sizeof(ENV_PATH) - 1) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}

char	*search_first_command(char *s1)
{
	char	*result;
	int		i;

	i = -1;
	while (s1[++i])
		if (s1[i] == ' ')
			break ;
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i--] = '\0';
	while (i >= 0)
	{
		result[i] = s1[i];
		i--;
	}
	return (result);
}
