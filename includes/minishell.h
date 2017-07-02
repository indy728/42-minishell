/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 01:25:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

# include "libft.h"
# include <sys/wait.h>

void	ms_echo(char **args);
char	is_open_quote(char *str, int pos);
char	is_escaped(char *str, int pos);
char	**ms_execute_command(char *command, char **env);
char	*ms_epurstr(char *str);
void	ms_convert_args(char **str, char **env);
char	**ms_strsplit(char *str, char c);
char	*find_arg(char **env, char *str);

#endif
