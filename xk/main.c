/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:29:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 15:09:03 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			addenv(char *env, int len)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char*) * (len + 2))))
	{
		ft_putendl("setenv : Malloc Error");
		return ;
	}
	i = 0;
	while (i < len)
	{
		new[i] = environ[i];
		i++;
	}
	new[i++] = env;
	new[i] = NULL;
	environ = new;
}

int				ft_stenverror(char *name, char *content)
{
	if (name == NULL || content == NULL)
	{
		ft_putendl("usage : setenv [Name] [Content]");
		return (0);
	}
	return (1);
}

void			ft_setenv(char *name, char *content)
{
	int		len;
	char	*env;
	int		i;
	char	*find;

	i = 0;
	len = 0;
	if (!ft_stenverror(name, content))
		return ;
	env = ft_strjoin_lite(ft_strjoin(name, "="), content);
	ft_putendl(env);
	find = ft_strjoin(name, "=");
	ft_putendl(find);
	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], find, ft_strlen(find)))
		{
			environ[i] = env;
			free(find);
			return ;
		}
		i++;
		len++;
	}
	free(find);
	addenv(env, len);
}

/*						GOOD 					*/

void	ft_echo(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '$')
			ft_putstr(ft_getenv(&argv[i][1]));
		else
			ft_putstr(argv[i]);
		if (argv[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_env(void)
{
	ft_puttables(environ);
}

void			ft_do_bui(char **argv, char *cmd, int rtn)
{
	if (rtn == ECHO)
		ft_echo(argv);
	else if (rtn == ENV)
		ft_env();
	else if (rtn == SETENV)
		ft_setenv(argv[1], argv[2]);
	if (cmd)
	return ;
	/*
	else if (rtn == UNSETENV)
		ft_unsetenv(argv);
	else if (rtn == CD)
		ft_cd(cmd);*/
}

/*       clear		 */

static int				ft_builtins(char **argv)
{
	char	*cmd;
	int		rtn;

	if (!argv)
		return (1);
	cmd = ft_strdup(argv[0]);
	rtn = ft_commands(argv, cmd);
	if (rtn != 0 && rtn != 100)
	{
		if (rtn == EXIT)
		{
			free(cmd);
			return (0);
		}
		ft_do_bui(argv, cmd, rtn);
	}
	if (rtn == 100)
		ft_namerror(cmd);
	free(cmd);
	return (1);
}

static int		ft_strisprint(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] >= 33 && str[i] <= 126 && str[i] != '"')
				return (1);
			i++;
		}
	}
	return (0);
}

static char		**cleartables(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (tab)
	{
		while (tab[i] != NULL)
		{
			len = ft_strlen(tab[i]);
			if (tab[i][0] == '"' && tab[i][len - 1] == '"')
				tab[i] = ft_strsub_lite(tab[i], 1, len - 2);
			i++;
		}
		return (tab);
	}
	return (NULL);
}

int				main(void)
{
	int		r;
	char	*input;
	char	**argv;

	input = ft_strnew(BUFFER_SIZE);
	while (1)
	{
		ft_username();
		ft_strclr(input);
		if (((r = read(0, input, BUFFER_SIZE)) <= 0) || !ft_strisprint(input))
			continue ;
		if (ft_strchr(input, '\n'))
			input = ft_strsub_lite(input, 0, ft_getindex(input, '\n'));
		if (!(argv = ft_strsplit_d(input, ' ', '\t')))
			continue ;
		if (!(ft_builtins(cleartables(argv))))
			break ;
		ft_freetable(argv);
	}
	double_free(input, argv);
	exit(EXIT_SUCCESS);
}
