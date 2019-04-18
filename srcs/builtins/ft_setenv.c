/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:55:06 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/16 19:55:28 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char        **addenv(char *env, int len)
{
    int i;
    char **new;

    if (!(new = (char **)malloc(sizeof(char*) * (len + 2))))
    {
        ft_putendl("malloc : error");
        return (environ);
    }
    new[len + 1] = NULL;
    i = 0;
    while (i < len)
    {
        new[i] = environ[i];
        i++;
    }
    new[i++] = env;
    return (new);
}

static char    *ft_strenv(char *name, char *content)
{
    char *new;
    int len;

    len = ft_strlen(name) + ft_strlen(content) + 1;
    new = ft_strnew(len);
    ft_strcpy(new, name);
    ft_strcat(new, "=");
    ft_strcat(new, content);
    return (new);
}

void	    ft_setenv(char *name, char *content)
{
    int len;
    char *env;
    int i;
    char **splited;

    i = 0;
    len = 0;
    if (name == NULL || content == NULL)
    {
        ft_putendl("usage : setenv [Name] [Content]");
        return ;
    }
    env = ft_strenv(name, content);
    while (environ[i] != NULL)
    {
        splited = ft_strsplit(environ[i], '=');
		if (ft_strequ(name, splited[0]))
		{
			environ[i] = env;
            ft_freetable(splited);
            return ;
		}
        i++;
        ft_freetable(splited);
        len++;
    }
    environ = addenv(env, len);
}
