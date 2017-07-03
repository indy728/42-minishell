/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 17:34:27 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"
# include <sys/wait.h>

# define SETENV_USAGE "usage: setenv [env var (must be alpha-numeric)] [optional = value]" 

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

char	g_exit;

char	*find_arg(char *str, char **env);
int		get_env_arg(char *str, char **env);
char	is_open_quote(char *str, int pos);
char	is_escaped(char *str, int pos);
void	ms_convert_args(char **str, char **env);
void	ms_echo(char **args);
char	*ms_epurstr(char *str);
char	**ms_execute_command(char *command, char **env);
char	**ms_setenv(char **args, char **env);
char	**ms_strsplit(char *str, char c);

#endif
