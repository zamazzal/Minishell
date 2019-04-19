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

int		ft_isbuiltin(char *cmd)
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


static char	*ft_strjoin_lite(char *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	free(s1);
	return (ptr);
}

char *ft_getcmd(char *path, char *cmd, char **paths)
{
	DIR *dir;
	int i;
	struct dirent *name;

	paths = ft_strsplit(path, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		dir = opendir(paths[i]);
		while ((name = readdir(dir)))
		{
			if (ft_strequ(cmd, name->d_name))
				return (ft_strjoin_lite(ft_strjoin(paths[i], "/"), cmd));
		}
		closedir(dir);
		i++;
	}
	return (NULL);
}

int		ft_iscmdpath(char *cmd, char **paths)
{
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(cmd);
	while (j >= 1 && cmd[j] != 47)
		j--;
	cmd = ft_strsub(cmd, 0, j);
	while (paths[i] != NULL)
	{
		if (ft_strnstr(cmd, paths[i], ft_strlen(paths[i])))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_iscmd(char *cmd)
{
	char *path;
	char **paths;
	char *rzlt;

	rzlt = NULL;
	path = ft_getenv("PATH");
	if (!path)
		return (NULL);
	paths = ft_strsplit(path, ':');
	if (ft_iscmdpath(cmd, paths))
	{
		ft_freetable(paths);
		return (cmd);
	}
	rzlt = ft_getcmd(path, cmd, paths);
	return (rzlt);
}

int		ft_commands(char **argv)
{
	pid_t	pid;
    int cmd;
	int		signal;

	signal = 0;
    if ((cmd = ft_isbuiltin(argv[0])))
        return (cmd);
	if ((argv[0] = ft_iscmd(argv[0])) == NULL)
		return (100);
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
