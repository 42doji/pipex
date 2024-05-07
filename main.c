#include "pipex.h"

void	clean_paths(char **res, int i)
{
	while (res[i])
		free(res[i--]);
	free(res);
}

char	**path_generator(char **env)
{
	char	*path;
	char	*temp;
	char	**paths;

	while (*env)
	{
		if (ft_strncmp("PATH=", *env, 5) == 0)
		{
			path = ft_dup(*env);
			break;
		}
		env++;
	}
	temp = (char *)malloc(sizeof(char) * (_len(path) + 1));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, path + 5, _len(path) - 5 + 1);
	paths = ft_split(temp , ";");
	free(path);
	free(temp);
	return (paths);
}

char	**filename_generator(char *arg, int argc)
{
	char	**file_names;
	
	file_names = (char **)malloc(sizeof(char *) * argc + 1);
	if (!file_names)
		return (NULL);
	file_names[0] = ft_dup(arg);
	file_names[1] = NULL;
	return (file_names);
}

int	main(int argc, char *argv[], char **env)
{
	char	**commands;
	char	**names;
	int	i;

	argc_handler(argc);
	
	return (0);
}
