//
// Created by dotte on 2024-05-01.
//

#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <unistd.h>

size_t	_len(char *s);
int 	count_words(const char *s, char *charset, char *dcharset);
int		is_split(char c, const char *charset);
int 	find_idx(char *s, char *charset, char *dcharset);
size_t	ft_strlcpy(char *d, char *s, size_t n);
char	**res_allocation(int size);
char	*word_allocation(char *s, char *charset, char *dcharset);
char	**clean_all(char **string, int i);
char	**ft_split(char *s, char *charset, char *dcharset);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
int 	argc_handler(int argc, const char *filepath);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_dup(char *s);
void	clean_paths(char **res, int i);
char	*path_generator(char **env);

#endif // PIPEX_H
