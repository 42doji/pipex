#include <stdio.h>
#include <unistd.h>
#include "pipex.h"

void	clean_paths(char **res, int i)
{
	while (res[i])
		free(res[i--]);
	free(res);
}

int main(int argc, char *argv[], char **env)
{
    char	*path;
	char	*temp;
	char	**paths;
	char	**file_names;
	char	**commands;
	int		i;

	argc_handler(argc);
	while (*env)
	{
		if (ft_strncmp("Path=", *env, 5) == 0)
		{
			path = ft_dup(*env);
			break;
		}
		env++;
	}
	temp = (char *)malloc(sizeof(char) * (_len(path)));
	if (!temp)
		return (0);
	ft_strlcpy(temp, path + 5, _len(path) - 5);
	free(path);
	paths = ft_split(temp , ";");
	if (!paths)
		return (0);
	i = 0;
	while (paths[i])
	{
		printf("%s\n", ft_strjoin_free(paths[i], "\\ls"));
		i++;
	};
	clean_paths(paths, i);
	free(temp);
	file_names = (char **)malloc(sizeof(char *) * argc + 1);
	file_names[0] = ft_dup(argv[1]);
	file_names[1] = NULL;
	commands = ft_split(argv[2], " ");
	char **temp2 = commands;
	while (*temp2)
	{
		printf("%s\n", *temp2++);
	}
	printf("%s\n", file_names[0]);
	clean_paths(commands, 2);
	free(file_names[0]);
	free(file_names[1]);
	free(file_names);
	return (0);
}