/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:32:28 by doji              #+#    #+#             */
/*   Updated: 2024/05/11 21:00:35 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# define ENV_PATH "PATH"
# define EXE_PATH "/bin/"
# define HERE_DOC "here_doc"

size_t	str_len(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*search_path(char **env);
char	*search_first_command(char *s1);
void	execve_error(char ***args, char **cmd, char **path);
void	ft_pipe(int pipefd[2]);
pid_t	ft_fork(void);
void	ft_dup2(int pipefd, int no);
void	ft_wait(int *status);
void	infile_check(const char *pathname);
void	open_infile(const char *pathname);
void	save_outfile(const char *pathname, int is_here_doc);
size_t	ft_strlcpy(char *dest, char *source, size_t n);
int		is_split(char c, const char *delimiter);
int		is_quotes(char c, const char *quotes);
int		has_delimiter(char *s, char *delimiter);
int		find_idx(char *s, char *delimiter, char *quotes);
int		count_words(const char *word, char *delimiter, char *quotes);
char	**ft_split(char *words, char *delimiter, char *quotes);
typedef struct s_list
{
	struct s_list	*next;
	char			*str;
	int				fd;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
t_list	*search_fd(int fd, t_list **list);
void	remove_fd(int fd, t_list **list);
int		len(char *str);
int		is_here_doc(const char *argv);
void	here_doc_input(const char *argv[]);
#endif
