/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:54:36 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/01 13:34:42 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	if (!ft_strncmp("PATH", *envp, 4))
		perror_error("no PATH");
	else
	{
		while (ft_strncmp("PATH", *envp, 4))
			envp++;
	}
	return (*envp + 5);
}

void	open_files(t_pipex *pipex, char **argv, int argc)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror_error("does not open argv[1]");
	pipex->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		close(pipex->infile);
		perror_error("does not open argv[argc - 1]");
	}
}

void	pipe_commands(t_pipex *pipex, char **argv, char **envp)
{
	if (pipe(pipex->fd) == -1)
		perror_error("pipex error");
	pipex->path = find_path(envp);
	if (pipex->path == NULL)
		perror_error("no PATH");
	pipex->cmds = ft_split(pipex->path, ':');
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		perror_error("fork error");
	if (pipex->pid1 == 0)
		first_child(*pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		perror_error("fork error");
	if (pipex->pid2 == 0)
		second_child(*pipex, argv, envp);
	close_pipe(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		err("incorrect number of arguments");
	open_files(&pipex, argv, argc);
	pipe_commands(&pipex, argv, envp);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_cmds(&pipex);
	return (0);
}
