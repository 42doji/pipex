#include "pipex.h"

void	clean_paths(char **res, int i)
{
	while (res[i])
		free(res[i--]);
	free(res);
}

char	*path_generator(char **env)
{
	char	*path;
	char	*temp;

	while (*env)
	{
		if (ft_strncmp("PATH=", *env, 5) == 0)
		{
			path = ft_dup(*env + 5);
			if (!path)
				return (NULL);
		}
		env++;
	}
	return (path);
}

int	main(int argc, char *argv[], char **env)
{
	char	*path;
	char	**args;
	int	count;

	count = argc_handler(argc, argv[1]);
	path = path_generator(env);
	
	return (0);
}
