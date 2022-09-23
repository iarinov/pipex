/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:00:14 by aiarinov          #+#    #+#             */
/*   Updated: 2022/08/01 13:32:04 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct pipex
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	*path;
	char	**cmds;
	char	**cmd_args;
	char	*command;
}t_pipex;

char	*find_path(char **envp);
void	open_files(t_pipex *pipex, char **argv, int argc);
char	*get_cmd(char *cmd, char **paths);
void	first_child(t_pipex pipex, char **argv, char **envp);
void	second_child(t_pipex pipex, char **argv, char **envp);
void	child_free(t_pipex *pipex);
void	close_pipe(t_pipex	*pipex);
void	parent_free(t_pipex *pipex);
int		err(char *msg);
void	perror_error(char *msg);
void	free_cmds(t_pipex *pipex);
void	pipe_commands(t_pipex *pipex, char **argv, char **envp);

#endif
