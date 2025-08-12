#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	puterr(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return puterr("error: cd: bad arguments\n");
	else if (chdir(argv[1]) != 0)
			return (puterr("error: cd: cannot change directory to "), puterr(argv[1]), puterr("\n"));
	return (0);
}

int	external(char **argv, char **ep, int i)
{
	int	fd[2];
	int	pid;
	int	pipeused = argv[i] && strcmp(argv[i], "|") == 0;

	if (pipeused && pipe(fd) != 0)
		return (puterr("error: fatal\n"));

	pid = fork();
	if (pid == 0)
	{
		argv[i] = NULL;
		if (pipeused && (dup2(fd[1], 1) == -1 || close(fd[0]) != 0 || close(fd[1]) != 0))
			return (puterr("error: cannot execute "), puterr(*argv), puterr("\n"));
		execve(*argv, argv, ep);
		return (puterr("error: cannot execute "), puterr(*argv), puterr("\n"));
	}
	else
	{
		waitpid(pid, NULL, 0);
		if (pipeused && (dup2(fd[0], 0) == -1 || close(fd[0]) != 0 || close(fd[1]) != 0))
			return (puterr("error: fatal\n"));
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	int 	i = 0;
	int		status = 0;

	while (argv[i] && argv[++i])
	{
		argv = argv + i;
		i = 0;

		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
			status = cd(argv, i);
		else if (i)
				status = external(argv, envp, i);
	}
	return (status);
}
