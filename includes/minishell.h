/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:52:39 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/29 12:42:40 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Include guard
*/

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**		Libraries
*/

# include "libft.h"
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <stdio.h>

/*
**		Indexes of Builtins
*/

# define ECHO 1
# define CD 2
# define SETENV 3
# define UNSETENV 4
# define ENV 5
# define EXIT 6
# define BUFFER_SIZE 1024

/*
**		Environment array
*/

char **g_environ;

/*
**		Commands
**		srcs/commands
*/

int		ft_commands(char **argv, char *name);
void	exec_cmd(char *exec, char **argv);

/*
**		Builtins
**		srcs/builtins
*/

char	*ft_getenv(const char *name);
void	ft_setinenv(int argc, char **argv);
void	ft_setenv(char *name, char *content);
void	ft_echo(int argc, char **argv);
void	ft_env(void);
int		ft_builtins(char **argv);
void	ft_unsetenv(char **name);
void	ft_cd(char **argv);

/*
**		Tools
**		srcs/tools
*/

char	*ft_strjoin_lite(char *s1, char const *s2);
char	*ft_strsub_lite(char *s, unsigned int start, size_t len);
char	**ft_strsplit_d(const char *str, char c, char x);
void	extra_free(char *dead1, char *dead2);
void	double_free(char *dead1, char **dead2);
void	ft_freetable(char **argv);
size_t	ft_getindex(char *str, char c);
size_t	ft_tablen(char **argv);
int		ft_strinstr(const char *s1, const char *s2, int len);

/*
**		Messages
**		srcs/messages
*/

void	ft_username(void);
void	ft_namerror(char *name);
void	ft_cmderror(char *cmd);
void	ft_permerror(char *cmd);
void	ft_notdir(char *name);
#endif
