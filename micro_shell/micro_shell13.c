#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void	ft_putstr_fd (int fd, char *str, char *arg)
{
	while (*str)
		write (fd, str++, 1);
	if (arg)
	{
		while (*arg)
			write (fd, arg++, 1);
	}
	write (fd, "\n", 1);
}

void	ft_execute (char **argv, int i, int temp_fd, char **envp)
{
	argv[i] = NULL;
	dup2 (temp_fd, STDIN_FILENO);
	close (temp_fd);
	execve(argv[0], argv, envp);
	ft_putstr_fd(2, "error: cannot execute ", argv[0]);
	exit(1);
}

int	main (int argc, char **argv, char **envp)
{
	int	i = 0;
	int	fd[2];
	int	temp_fd;

	(void) argc;
	temp_fd = dup (STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp (argv[i], ";") && strcmp (argv[i], "|"))
			i++;
		if (!strcmp (argv[0], "cd"))
		{
			if (i != 2)
				ft_putstr_fd (2, "error: cd: bad arguments ", NULL);
			else if (chdir (argv[1]))
				ft_putstr_fd (2, "error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (!argv[i] || !strcmp (argv[i], ";")))
		{
			if (fork () == 0)
				ft_execute(argv, i, temp_fd, envp);
			else 
			{
				close(temp_fd);
				while (waitpid (-1, NULL, WUNTRACED) != -1)
					;
				temp_fd = dup (STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp (argv[i], "|"))
		{
			pipe(fd);
			if (fork () == 0)
			{
				dup2 (fd[1], STDOUT_FILENO);
				close (fd[0]);
				close (fd[1]);
				ft_execute(argv, i , temp_fd, envp);
			}
			else
			{
				close (fd[1]);
				close (temp_fd);
				temp_fd = fd[0];
			}
		}
	}
	close (temp_fd);
	return (0);
}
