/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:34:44 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 16:36:53 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_freetable(char **argv)
{
	int i;

	i = 0;
	if (*argv)
	{
		while (argv[i] != NULL)
			free(argv[i++]);
		free(argv);
	}
}

char			*ft_strsub_lite(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ptr = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	free(s);
	return (ptr);
}

char	*ft_strjoin_lite(char *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	free(s1);
	return (ptr);
}

size_t			ft_getindex(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void			double_free(char *dead1, char **dead2)
{
	if (dead1)
		free(dead1);
	if (*dead2)
		ft_freetable(dead2);
}
