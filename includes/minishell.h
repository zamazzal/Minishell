/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 00:07:01 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/15 16:16:30 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_ls.h"
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>

#define ECHO 1
#define CD 2
#define PWD 3
#define SETENV 4
#define UNSETENV 5
#define ENV 6
#define LS 7
#define EXIT 8

#define CLEAR "e[1;1H\e[2J"

extern char **environ;

void	ft_freetable(char **argv);
void	ft_username(void);
void    ft_namerror(char *name);
char    *ft_getenv(const char *name);
void    ft_env(void);
int     ft_arraylen(char **tab);
void	ft_unsetenv(char **name);
void	ft_echo(char **argv);
void	ft_setenv(char *name, char *content);
char	*ft_strsub_lite(char *s, unsigned int start, size_t len);
void	ft_cd(char *path);
int     ls(char **argv);
int     ft_commands(char **argv);
#endif