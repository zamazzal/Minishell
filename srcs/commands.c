/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:10:54 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/17 19:11:28 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isbuiltin(char *cmd)
{
    if (ft_strequ(cmd, "echo"))
		return (ECHO);
	else if (ft_strequ(cmd, "cd"))
		return (CD);
	else if (ft_strequ(cmd, "pwd"))
		return (PWD);
	else if (ft_strequ(cmd, "setenv"))
		return (SETENV);
	else if (ft_strequ(cmd, "unsetenv"))
		return (UNSETENV);
	else if (ft_strequ(cmd, "env"))
		return (ENV);
	else if (ft_strequ(cmd, "ls"))
		return (LS);
	else if (ft_strequ(cmd, "exit"))
		return (EXIT);
	else if (!ft_strnstr(cmd, "/bin/", 5) && !ft_strnstr(cmd, "/usr/bin/", 9))
		return (100);
    return (0);
}

int ft_commands(char **argv)
{
	pid_t	pid;
    int cmd;
	int		signal;

	signal = 0;
    if ((cmd = ft_isbuiltin(argv[0])))
        return (cmd);
	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, environ);
	}
	else
	{
		wait(&signal);
		if (signal != 0)
			kill(pid, signal);
	}
    return (0);
}
