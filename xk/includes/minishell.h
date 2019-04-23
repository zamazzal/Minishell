/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 19:52:39 by zamazzal          #+#    #+#             */
/*   Updated: 2019/04/22 16:45:08 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>

# define ECHO 1
# define CD 2
# define SETENV 3
# define UNSETENV 4
# define ENV 5
# define EXIT 6
# define BUFFER_SIZE 1024

extern char **environ;

int		ft_commands(char **argv, char *name);
void    exec_cmd(char *exec, char **argv);

char	*ft_getenv(const char *name);

char	*ft_strjoin_lite(char *s1, char const *s2);
char	*ft_strsub_lite(char *s, unsigned int start, size_t len);
char	**ft_strsplit_d(const char *str, char c, char x);
void	double_free(char *dead1, char **dead2);
void	ft_freetable(char **argv);
size_t	ft_getindex(char *str, char c);

void	ft_username(void);
void	ft_namerror(char *name);
void	ft_cmderror(char *cmd);
#endif
