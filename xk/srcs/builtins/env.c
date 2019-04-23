/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:42:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 16:42:51 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_getenv(const char *name)
{
	int		i;
	int		len;
	char	*env;

	i = 0;
	if (!name)
		return (NULL);
	env = ft_strjoin(name, "=");
	len = ft_strlen(env);
	while (environ[i] != NULL)
	{
		if (ft_strnstr(environ[i], env, len))
		{
			free(env);
			return (ft_strchr(environ[i], '=') + 1);
		}
		i++;
	}
	free(env);
	return (NULL);
}
