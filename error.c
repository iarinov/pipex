/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:32:44 by aiarinov          #+#    #+#             */
/*   Updated: 2022/07/25 15:27:12 by aiarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}

void	perror_error(char *msg)
{
	perror(msg);
	exit(1);
}
