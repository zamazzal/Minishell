/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhair.amazzal@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:56:20 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 18:01:59 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_removeenv(char *name)
{
	int		i;
	int		j;
	char	**new;
	int		len;
	char	**splited;

	len = ft_arraylen(environ);
	new = (char **)malloc(sizeof(char *) * len);
	i = 0;
	j = 0;
	while (environ[i] != NULL)
	{
		splited = ft_strsplit(environ[i], '=');
		if (!(ft_strequ(name, splited[0])))
		{
			new[j] = ft_strdup(environ[i]);
			j++;
		}
		ft_freetable(splited);
		i++;
	}
	new[i] = NULL;
	environ = new;
}

void			ft_unsetenv(char **name)
{
	int i;

	i = 1;
	while (name[i] != NULL)
	{
		ft_removeenv(name[i]);
		i++;
	}
	if (i == 1)
		ft_putendl("usage : unsetenv [Name]");
}
