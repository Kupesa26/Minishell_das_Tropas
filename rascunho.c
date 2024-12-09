#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define CMD_COUNT 4

void	execute_pipeline(char *commands[CMD_COUNT][3], const char *output_file)
{
	int		i;
	int		pipefd[2];
	int		prev_pipe;
	int		file;
	pid_t	pid;

	i = 0;
	prev_pipe = -1;
	while (i < CMD_COUNT)
	{
		if (i < CMD_COUNT - 1)
		{
			if (pipe(pipefd) == -1)
			{
				perror ("pipe");
				exit (EXIT_FAILURE);
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit (EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (i < CMD_COUNT - 1)
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
				close(pipefd[0]);
			}
			else
			{
				file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (file == -1)
				{
					perror("open");
					exit(EXIT_FAILURE);
				}
				dup2(file, STDOUT_FILENO);
				close(file);
			}
			execvp(commands[i][0], commands[i]);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (prev_pipe != -1)
			{
				close(prev_pipe);
			}
			if (i < CMD_COUNT - 1)
			{
				close(pipefd[1]);
				prev_pipe = pipefd[0];
			}
		}
		i++;
	}
	i = 0;
	while (i < CMD_COUNT)
	{
		wait(NULL);
		i++;
	}
}

int	main(void)
{
	char	*commands[CMD_COUNT][3] = {
        { "ls", "-l", NULL },
        { "grep", ".c", NULL },
        { "sort", NULL },
        { "wc", "-l", NULL }
    };

    execute_pipeline(commands, "output.txt");
    return 0;
}



