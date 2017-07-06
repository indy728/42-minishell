/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:33:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/05 20:13:10 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_variables(char *str, char **env)
{
	char	*new;
	int		i;
	int		j;
	char	*env_arg;
	char	help[CWD_BUF];

	i = -1;
	new = ft_strdup(str);
	while (str[++i])
	{
		j = 1;
		if (str[i] == '$' && is_open_quote(str, i) != '\'')
		{
			while (ft_isalnum(str[i + j]))
				++j;
			if (!(env_arg = find_arg(str + i + 1, env)))
				env_arg = ft_strdup("");
			new = ft_strmove(ft_strsubstr(new,
					ft_strncpy(help, str + i, j), env_arg),
					&new);
			ft_strdel(&env_arg);
		}
	}
	return (new);
}

char	*remove_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = ft_strnew(CWD_BUF);
	while (str[++i])
	{
		if ((str[i] == '"' && is_open_quote(str, i) != '\'')
				|| (str[i] == '\'' && is_open_quote(str, i) != '"'))
			continue ;
		else
			new[j++] = str[i];
	}
	return (new);
}

char	get_escapechar(char c)
{
	if (c == 'a')
		return (7);
	if (c == 'b')
		return (8);
	if (c == 't')
		return (9);
	if (c == 'n')
		return (10);
	if (c == 'v')
		return (11);
	if (c == 'f')
		return (12);
	else
		return (13);
}

char	*handle_escapes(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	new = ft_strnew(CWD_BUF);
	while (str[++i])
	{
		if (str[i] == '\\')
		{
			while (str[i + 1] == '\\')
				++i;
			if (ft_strchr("abfnrtv", str[i + 1]))
			{
				new[j++] = get_escapechar(str[i + 1]);
				++i;
			}
			++i;
		}
		new[j++] = str[i];
	}
	return (new);
}

void	ms_convert_args(char **args, char **env)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		args[i] = ft_strmove(handle_escapes(args[i]), &(args[i]));
		args[i] = ft_strmove(handle_variables(args[i], env), &(args[i]));
		args[i] = ft_strmove(remove_quotes(args[i]), &(args[i]));
		if (!ft_strcmp(args[i], "~"))
			args[i] = ft_strmove(find_arg("HOME", env), &(args[i]));
	}
}
