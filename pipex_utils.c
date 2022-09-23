/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:01:58 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/01 11:15:45 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *cmd, char **paths)
{
	char	*tmp;
	char	*command;

	if (ft_strchr(cmd, '/') != 0 && access(cmd, 0) == 0)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		free(*paths);
		command = ft_strjoin(tmp, cmd);
		if (!command)
			exit(1);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (!pipex.cmd_args[0])
		err("command not found");
	pipex.command = get_cmd(pipex.cmd_args[0], pipex.cmds);
	if (!pipex.command)
	{
		child_free(&pipex);
		err("first command not found");
		exit(1);
	}
	execve(pipex.command, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.command = get_cmd(pipex.cmd_args[0], pipex.cmds);
	if (!pipex.command)
	{
		child_free(&pipex);
		err("second command not found");
		exit(1);
	}
	execve(pipex.command, pipex.cmd_args, envp);
}
