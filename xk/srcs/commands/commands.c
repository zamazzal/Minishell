/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:22:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 19:25:14 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isbuiltin(char *cmd)
{
	if (ft_strequ(cmd, "echo"))
		return (ECHO);
	else if (ft_strequ(cmd, "cd"))
		return (CD);
	else if (ft_strequ(cmd, "setenv"))
		return (SETENV);
	else if (ft_strequ(cmd, "unsetenv"))
		return (UNSETENV);
	else if (ft_strequ(cmd, "env"))
		return (ENV);
	else if (ft_strequ(cmd, "exit"))
		return (EXIT);
	return (0);
}

static char		*ft_getcmd(char *cmd, char **paths)
{
	char			*real;
	DIR				*dir;
	int				i;
	struct dirent	*name;

	i = 0;
	real = NULL;
	while (paths[i] != NULL && !real)
	{
		dir = opendir(paths[i]);
		while ((name = readdir(dir)) && !real)
		{
			if (ft_strequ(cmd, name->d_name))
				real = ft_strjoin_lite(ft_strjoin(paths[i], "/"), cmd);
		}
		closedir(dir);
		i++;
	}
	return (real);
}

static int		ft_iscmdpath(char *cmd, char **paths)
{
	char	*mycmd;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(cmd);
	while (j >= 1 && cmd[j] != 47)
		j--;
	mycmd = ft_strsub(cmd, 0, j);
	while (paths[i] != NULL)
	{
		if (ft_strnstr(mycmd, paths[i], ft_strlen(paths[i])))
		{
			free(mycmd);
			return (1);
		}
		i++;
	}
	free(mycmd);
	return (0);
}

static char		*ft_iscmd(char *cmd)
{
	char *path;
	char **paths;
	char *rzlt;

	rzlt = NULL;
	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	if (!(paths = ft_strsplit(path, ':')))
		return (NULL);
	if (ft_iscmdpath(cmd, paths))
	{
		ft_freetable(paths);
		return (ft_strdup(cmd));
	}
	rzlt = ft_getcmd(cmd, paths);
	ft_freetable(paths);
	return (rzlt);
}

int				ft_commands(char **argv, char *name)
{
	char	*exec;
	int		cmd;

	if ((cmd = ft_isbuiltin(name)))
		return (cmd);
	if ((exec = ft_iscmd(name)) == NULL)
		return (100);
	exec_cmd(exec, argv);
	free(exec);
	return (0);
}
