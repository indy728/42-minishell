/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 16:27:46 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 00:12:31 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		unsetenv_usage(char **args)
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

char	**ms_unsetenv(char **args, char **env)
{
	char	**new;
	int		n;

	if (!unsetenv_usage(args))
	{
		ft_printf("usage: unsetenv: "UNSETENV_USAGE"\n");
		return (env);
	}
	n = get_env_arg(args[1], env);
	if (n < 0)
		ft_printf("environment variable '%s' does not exist!\n", args[1]);
	else if (!ft_strcmp(args[1], "HOME")
			|| !ft_strcmp(args[1], "PWD")
			|| !ft_strcmp(args[1], "OLDPWD"))
		ft_printf("illegal unset: do not unset $%s\n", args[1]);
	else
	{
		new = ft_pop_r(env, n);
		ft_del_r(env);
		return (new);
	}
	return (env);
}
