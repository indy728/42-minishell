/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:07:13 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 18:45:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ms_execute_command(char *command, char **env)
{
	char	**args;

//	command = ms_epurstr(command);
//	command = ms_convert_args(command, env);
	ft_printf("command: %s\n", command);
	args = ms_strsplit(command, ' ');
	ft_print_r(args);
	ft_del_r(args);
	return (env);
}
