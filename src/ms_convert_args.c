/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:33:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 17:18:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_variables(char **str, char **env)
{
	char	new[1024];
	int		i;
	int		j;
	char	*env_arg;

	i = -1;	
	j = 0;
	ft_memset(new, 0, 1024);
	while ((*str)[++i])
	{
		if ((*str)[i] != '$' || is_open_quote((*str), i) == '\'')
			new[j++] = (*str)[i];
		else if ((env_arg = find_arg((*str) + ++i, env)))
		{
			ft_strcat(new, env_arg);
			j += ft_strlen(env_arg);
			while (ft_isalnum((*str)[i + 1]))
				++i;
			ft_strdel(&env_arg);
		}
		else
		{	
			while (ft_isalnum((*str)[++i + 1]))
				;
		}
	}
	new[j] = '\0';
	ft_strdel(str);
	return(ft_strdup(new));
}

char	*remove_quotes(char **str)
{
	char	new[1024];
	int		i;
	int		j;

	i = -1;	
	j = 0;
	ft_memset(new, 0, 1024);
	while ((*str)[++i])
	{
		if (((*str)[i] == '"' && is_open_quote((*str), i) != '\'')
				|| ((*str)[i] == '\'' && is_open_quote((*str), i) != '"'))
			continue ;
		else
			new[j++] = (*str)[i];
	}
	new[j] = '\0';
	ft_strdel(str);
	return(ft_strdup(new));
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

char	*handle_escapes(char **str)
{
	char	new[1024];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while ((*str)[++i])
	{
		if ((*str)[i] == '\\')
		{
			while ((*str)[i + 1] == '\\')
				++i;
			if (ft_strchr("abfnrtv", (*str)[i + 1]))
			{
				new[j++] = get_escapechar((*str)[i + 1]);
				++i;
			}
			++i;
		}
		new[j++] = (*str)[i];
	}
	new[j] = '\0';
	ft_strdel(str);
	return(ft_strdup(new));
}

void	ms_convert_args(char **args, char **env)
{
	int		i;

	i = -1;
	while (args[++i])
	{
		args[i] = handle_escapes(&(args[i]));
		args[i] = handle_variables(&(args[i]), env);
		args[i] = remove_quotes(&(args[i]));
	}
}
