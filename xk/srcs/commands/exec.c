/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:27:13 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 19:27:50 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char *exec, char **argv)
{
	pid_t	pid;
	int		signal;

	signal = 0;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		if (execve(exec, argv, environ) < 0)
			ft_cmderror(exec);
		exit (0);
	}
	else
	{
		wait(NULL);
		kill(pid, SIGKILL);
	}
}
