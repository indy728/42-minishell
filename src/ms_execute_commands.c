/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:07:13 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 01:24:13 by kmurray          ###   ########.fr       */
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
	if (!ft_strcmp(args[0], "echo"))
		ms_echo(args);
	ft_del_r(args);
	return (env);
}
