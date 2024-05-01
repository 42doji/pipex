//
// Created by dotte on 2024-05-01.
//

#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <malloc.h>



size_t	_len(char *s);
int 	count_words(const char *s, char *charset);
int		is_split(char c, const char *charset);
int 	find_idx(char *s, char *charset);
int 	ft_strlcpy(char *d, const char *s, int size);
char	**res_allocation(int size);
char	*word_allocation(char *s, char *charset);
char	**clean_all(char **string, int i);
char	**ft_split(char *s, char *charset);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif // PIPEX_H
