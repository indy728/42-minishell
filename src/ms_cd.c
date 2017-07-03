/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 19:42:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 23:14:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pwd(char *oldpwd, char **env)
{
	char	*tmp;
	int		n;
	char	cwd[CWD_BUF];

	if ((n = get_env_arg("OLDPWD", env)) < 0)
		/*sudo_set("OLDPWD", oldpwd, env)*/;
	else
	{
		tmp = env[n]; 
		env[n] = ft_strjoin("OLDPWD=", oldpwd);
		ft_strdel(&tmp);
	}
	getcwd(cwd, CWD_BUF);
	if ((n = get_env_arg("PWD", env)) < 0)
		/*sudo_set("PWD", cwd, env)*/;
	else
	{
		tmp = env[n]; 
		env[n] = ft_strjoin("PWD=", cwd);
		ft_strdel(&tmp);
	}
}

void	chdir_err(char *invalid)
{
	char	*msg;

	if (access(invalid, F_OK) == -1)
		msg = ft_strdup("no such file or directory: ");
	else if (access(invalid, R_OK) == -1)
		msg = ft_strdup("permission denied: ");
	else
		msg = ft_strdup("not a directory: ");
	ft_printf("cd: %s%s\n", msg, invalid);
	ft_strdel(&msg);
}

char	**ms_cd(char **args, char **env)
{
	char	*new_dir;
	char	cwd[CWD_BUF];

	//check if HOME exists
	if (!args[1] || !ft_strcmp(args[1], "~"))
		new_dir = ft_strdup(find_arg("HOME", env));
	else
		new_dir = ft_strdup(args[1]);
	getcwd(cwd, CWD_BUF);
	if (chdir(new_dir) < 0)
		chdir_err(new_dir);
	else
		set_pwd(cwd, env);
	ft_strdel(&new_dir);
	return (env);
}
