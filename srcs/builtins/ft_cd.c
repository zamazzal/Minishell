/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:56:35 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/17 15:57:16 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_checkaccess(char *path, char *name)
{
    struct stat buf;

    if (access(path, F_OK))
    {
        ft_putstr("cd: no such file or directory: ");
        ft_putendl(name);
        return (0);
    }
    if (access(path, X_OK))
    {
        ft_putstr("cd: permission denied: ");
        ft_putendl(name);
        return (0);
    }
    lstat(path, &buf);
    if (!(buf.st_mode & 0040000) && !(buf.st_mode & 0120000))
    {
        ft_putstr("cd: not a directory: ");
        ft_putendl(name);
        return (0);
    }
    return (1);
}

void    ft_entre(char *path, char *name)
{
    char *now;

    if (ft_checkaccess(path, name))
    {
        chdir(path);
        now = getcwd(ft_strnew(1023 + ft_strlen(path) + 1), 1024);
        ft_setenv("PWD", now);
        free(now);
    }
}

void	ft_cd(char *path)
{
    char *old;
    char *now;

    if (path == NULL || path[0] == '~')
        path = ft_getenv("HOME");
    if (path[0] == '$')
        path = ft_getenv(&path[1]);
    if (path[0] == '-')
    {
        now = ft_getenv("OLDPWD");
        old = getcwd(ft_strnew(1023), 1024);
        ft_setenv("OLDPWD", old);
        ft_entre(now, now);
        free(old);
        return ;
    }
    old = getcwd(ft_strnew(1023), 1024);
    ft_setenv("OLDPWD", old);
    free(old);
    if (path[0] != '/' && path[0] != '.' && path[0] != '-')
    {
        now = getcwd(ft_strnew(1023 + ft_strlen(path) + 1), 1024);
        ft_strcat(ft_strcat(now, "/"), path);
        ft_entre(now, path);
        return ;
    }
    ft_entre(path, path);
}