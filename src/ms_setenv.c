/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 16:27:46 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 20:05:09 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*new_env_var(char **args)
{
	char	*str;

	str = args[2]
		? ft_strnew(ft_strlen(args[1]) + 1 + ft_strlen(args[2]))
		: ft_strnew(ft_strlen(args[1]) + 1);
	str = ft_strcpy(str, args[1]);
	str = ft_strcat(str, "=");
	if (args[2])
		str = ft_strcat(str, args[2]);
	return (str);
}

int		setenv_usage(char **args)
{
	int	i;

	i = -1;
	if (!args[1])
		return (0);
	while (args[1][++i])
	{
		if (!ft_isalnum(args[1][i]))
			return (0);
	}
	return (1);
}

char	**ms_setenv(char **args, char **env)
{
	char	**new;
	int		n;
	char	*tmp;

	if (!setenv_usage(args))
	{
		ft_printf("usage: setenv: "SETENV_USAGE"\n");
		return (env);
	}
	n = get_env_arg(args[1], env);
	if (n < 0)
	{
		new = ft_dupn_r(env, ft_size_r(env) + 1);
		new[ft_size_r(env)] = new_env_var(args);
	}
	else
	{
		new = ft_dupn_r(env, ft_size_r(env));
		tmp = new[n];
		new[n] = new_env_var(args);
		ft_strdel(&tmp);
	}
	ft_del_r(env);
	return (new);
}
