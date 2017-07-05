/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:07:13 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/04 19:49:30 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ms_execute_command(char *command, char **env)
{
	char	**args;

	command = ms_epurstr(command);
	args = ms_strsplit(command, ' ');
	ft_strdel(&command);
	ms_convert_args(args, env);
	if (!*args[0])
		;
	else if (!ft_strcmp(args[0], "echo"))
		ms_echo(args);
	else if (!ft_strcmp(args[0], "cd"))
		env = ms_cd(args, env);
	else if (!ft_strcmp(args[0], "env"))
		ft_print_r(env);
	else if (!ft_strcmp(args[0], "setenv"))
		env = ms_setenv(args, env);
	else if (!ft_strcmp(args[0], "unsetenv"))
		env = ms_unsetenv(args, env);
	else if (!ft_strcmp(args[0], "exit"))
		g_exit = 1;
	else
		ms_exe(args, env);
	ft_del_r(args);
	return (env);
}
