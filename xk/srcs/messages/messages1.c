/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:38:57 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 16:39:11 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_username(void)
{
	char *name;

	name = ft_getenv("USER");
	if (name)
		ft_putstr(name);
	ft_putstr(" $> ");
}

void	ft_namerror(char *name)
{
	if (name)
		ft_putstr(name);
	ft_putendl(": command not found");
}

void	ft_cmderror(char *cmd)
{
	if (cmd)
		ft_putstr(cmd);
	ft_putendl(": No such file or directory");
}