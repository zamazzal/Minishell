/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:18:08 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 18:01:01 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	char	**infos;
	int		i;

	i = 0;
	while (environ[i] != NULL)
	{
		infos = ft_strsplit(environ[i], '=');
		if (ft_strequ(infos[0], name))
		{
			ft_freetable(infos);
			return (ft_strchr(environ[i], '=') + 1);
		}
		ft_freetable(infos);
		i++;
	}
	return (NULL);
}
