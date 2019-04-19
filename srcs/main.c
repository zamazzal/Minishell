/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:18:17 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 18:04:47 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int		ft_builtins(char **argv)
{
	char	*cmd;
	int		rtn;
	
	cmd = argv[0];
	if ((rtn = ft_commands(argv)))
	{
		if (rtn == ECHO)
			ft_echo(argv);
		else if (rtn == CD)
			ft_cd(argv[1]);
		else if (rtn == SETENV)
			ft_setenv(argv[1], argv[2]);
		else if (rtn == UNSETENV)
			ft_unsetenv(argv);
		else if (rtn == ENV)
			ft_env();
		else if (rtn == EXIT)
			return (0);
		else if (rtn == 100)
			ft_namerror(cmd);
	}
	return (1);
}

static char		**cleartables(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i] != NULL)
	{
		len = ft_strlen(tab[i]);
		if (tab[i][0] == '"' && tab[i][len - 1] == '"')
		{
			tab[i] = ft_strsub_lite(tab[i], 1, len - 2);
		}
		i++;
	}
	return (tab);
}

int				ft_checkinput(char *input)
{
	int		i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 33 && input[i] <= 126)
			return (1);
		i++;
	}
	return (0);
}

int				main(void)
{
	int		n;
	char	*input;
	char	**argv;

	input = ft_strnew(1024);
	while (1)
	{
		n = 0;
		ft_username();
		ft_strclr(input);
		read(0, input, 1024);
		while (input[n] != '\n')
			n++;
		if (input == NULL)
			break ;
		input = ft_strsub_lite(input, 0, n);
		if (ft_checkinput(input))
		{
			argv = ft_strsplit(input, ' ');
			cleartables(argv);
			if (!(ft_builtins(argv)))
				break ;
			ft_freetable(argv);
		}
	}
	ft_freetable(argv);
	free(input);
	exit (1);
}
