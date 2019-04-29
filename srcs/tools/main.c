/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:29:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/29 12:49:01 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char		**ctables(char **tab)
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

static char		**ft_tabdup(char **tab)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 1))))
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (new);
}

int				main(void)
{
	int				r;
	char			*input;
	char			**argv;
	extern char		**environ;

	g_environ = ft_tabdup(environ);
	while (1)
	{
		input = ft_strnew(BUFFER_SIZE);
		ft_username();
		ft_strclr(input);
		if (((r = read(0, input, BUFFER_SIZE)) <= 0) || !ft_strisprint(input))
		{
			ft_strdel(&input);
			continue ;
		}
		if ((r = ft_getindex(input, '\n')) > 0)
			input = ft_strsub_lite(input, 0, r);
		argv = ft_strsplit_d(input, ' ', '\t');
		if (!(ft_builtins(ctables(argv))))
			break ;
		double_free(input, argv);
	}
	double_free(input, argv);
	exit(EXIT_SUCCESS);
}
