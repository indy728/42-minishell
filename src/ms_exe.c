/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 23:53:01 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/03 01:00:40 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ms_add_exe(char **paths, char *exe)
{
	int		i;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		ft_strdel(&tmp);
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], exe);
		ft_strdel(&tmp);
	}
	return (paths);
}

int	ms_exe(char **args, char **env)
{
	char	*str;
	char	**paths;
	pid_t	pid;
	int		i;

	if(!(str = find_arg("PATH", env)))
		return (0);
	i = -1;
	paths = ft_strsplit(str, ':');
	paths = ms_add_exe(paths, args[0]);
	ft_strdel(&str);
	pid = fork();
	if (!pid)
	{
		while (paths[++i])
			execve(paths[i], args, env);
		ft_printf("%s: command not found.\n", args[0]);
	}
	else if (pid < 0)
		return (-1);
	wait(&pid);
	ft_del_r(paths);
	return (1);
}
