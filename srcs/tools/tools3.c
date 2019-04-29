/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:38:55 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/28 20:19:02 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_strinstr(const char *s1, const char *s2, int len)
{
	int i;
	int j;

	if (!s1)
		return (0);
	if (s2[0] == '\0')
		return (1);
	i = 0;
	while ((s1[i] != '\0') && (i < len))
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i + j] != s2[j] || j + i >= len)
				break ;
			j++;
		}
		if (s2[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void			double_free(char *dead1, char **dead2)
{
	if (dead1)
		ft_strdel(&dead1);
	if (*dead2)
		ft_freetable(dead2);
}

void			extra_free(char *dead1, char *dead2)
{
	if (dead1)
		ft_strdel(&dead1);
	if (dead2)
		ft_strdel(&dead2);
}
