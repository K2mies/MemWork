#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void	ft_putstr_fd(int fd, char *str, char *arg)
{
	while (*str)
		write(fd, str++, 1);
	if (arg)
	{
		while (*arg)
			write(fd, arg++, 1);
	}
	write(fd, "\n", 1);
}

void	ft_execute(char **argv, int i, int fd_temp, char **envp)
{
	argv[i] = NULL;
	dup2(fd_temp, STDIN_FILENO);
	close(fd_temp);
	execve(argv[0], argv, envp);
	ft_putstr_fd(2, "error: cannot execute ", argv[0]);
	exit(1);
}

int	main(int arc, char **argv, char **envp)
{
	int	i = 0;
	int	fd[2];
	int	temp_fd;

	(void)argc;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (!strncmp(argv[i], "cd"))
		{
			if (i != 2)
				ft_putstr_fd(2, "error: cd: bad arguments ", NULL);
			else if (chdir(argv[0]))
					ft_putstr_fd(2, "error: cd: cannot change directory to ", argv[1])
		}
	}
}
