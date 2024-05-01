#include <stdio.h>
#include <unistd.h>
#include "pipex.h"

int argc_handler(int argc)
{
	int r;

	r = 0;
	if (argc <= 1 )
		printf("Error: Needs Args.\n");
	else if (argc / 2 != 0)
		printf("Error: Wrong Arg counts.");
	else
		r = 1;
	if (!r)
		exit(0);
	else
		return (argc - 1);
}

void	clean_paths(char **res, int i)
{
	while (res[i])
		free(res[i--]);
	free(res);
}

int main(int argc, char *argv[], char **env)
{
    // argc_handler(argc);
    // argv의 0번째 인자는 실행파일 이름이므로 1부터 시작
    // argv[1] = infile, argv[2] = cmd1, argv[3] = cmd2, argv[4] = outfile
    char	*path;
	char	*temp;
	char	**res;
	int		i;

	i = 0;
	while (*env)
	{
		if (ft_strncmp("Path=", *env, 5) == 0)
		{
			path = *env;
			break;
		}
		*env++;
	}
	temp = (char *)malloc(sizeof(char) * (_len(path)));
	ft_strlcpy(temp, path + 5, _len(path) - 5);
	res = ft_split(temp , ";");
	while (res[i])
		printf("%s\n", res[i++]);
	clean_paths(res, i);
	free(temp);
	return (0);
}