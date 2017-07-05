/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 19:42:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/04 20:51:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pwd(char *oldpwd, char **env)
{
	char	*tmp;
	int		n;
	char	cwd[CWD_BUF];

	getcwd(cwd, CWD_BUF);
	n = get_env_arg("OLDPWD", env);
	tmp = env[n];
	env[n] = ft_strjoin("OLDPWD=", oldpwd);
	ft_strdel(&tmp);
	n = get_env_arg("PWD", env);
	tmp = env[n];
	env[n] = ft_strjoin("PWD=", cwd);
	ft_strdel(&tmp);
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

char	*goto_last(char **env)
{
	char	*tmp;
	char	*home;
	int		n;

	tmp = find_arg("OLDPWD", env);
	home = find_arg("HOME", env);
	if ((n = ft_strlnstr(tmp, home)) < 0)
		ft_printf("%s\n", tmp);
	else
		ft_printf("~%s\n", tmp + n);
	ft_strdel(&home);
	return (tmp);
}

char	**ms_cd(char **args, char **env)
{
	char	*new_dir;
	char	cwd[CWD_BUF];
	char	*tmp;

	getcwd(cwd, CWD_BUF);
	if (!args[1] || *args[1] == '~')
	{
		tmp = find_arg("HOME", env);
		if (args[1])
			new_dir = ft_strjoin(tmp, args[1] + 1);
		else
			new_dir = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (*args[1] == '-')
		new_dir = goto_last(env);
	else
		new_dir = ft_strdup(args[1]);
	if (chdir(new_dir) < 0)
		chdir_err(new_dir);
	else
		set_pwd(cwd, env);
	ft_strdel(&new_dir);
	return (env);
}
