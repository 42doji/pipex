/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:34:16 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 20:08:59 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
