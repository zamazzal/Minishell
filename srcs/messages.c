/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:17:42 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 16:19:31 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_namerror(char *name)
{
	ft_putstr(name);
	ft_putendl(": command not found");
}

void	ft_username(void)
{
	char *name;

	name = ft_getenv("USER");
	if (name)
		ft_putstr(name);
	ft_putstr(" $> ");
}
