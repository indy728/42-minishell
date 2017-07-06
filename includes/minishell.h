/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 21:51:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <signal.h>

# define SETENV_USAGE "[env var (must be alpha-numeric)] [optional: value]"
# define UNSETENV_USAGE "[env var (must be alpha-numeric)]"
# define MS_USAGE "-p [custom line prompt] [optional: color]"

# define CWD_BUF 1024

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BBLACK "\x1b[40m"
# define BRED "\x1b[41m"
# define BGREEN "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE "\x1b[44m"
# define BMAGENTA "\x1b[45m"
# define BCYAN "\x1b[46m"
# define BWHITE "\x1b[47m"
# define RESET "\x1b[0m"
# define CLEAR "\033c"
# define BOLD "\033[1m"

char	g_exit;
char	g_nl;

char	*find_arg(char *str, char **env);
int		get_env_arg(char *str, char **env);
char	is_open_quote(char *str, int pos);
char	is_escaped(char *str, int pos);
char	**ms_cd(char **args, char **env);
void	ms_convert_args(char **str, char **env);
void	ms_echo(char **args);
char	*ms_epurstr(char *str);
int		ms_exe(char **args, char **env);
char	**ms_execute_command(char *command, char **env);
char	**ms_setenv(char **args, char **env);
char	**ms_strsplit(char *str, char c);
char	**ms_unsetenv(char **str, char **env);

#endif
