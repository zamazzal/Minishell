/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:47:34 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 17:48:05 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
