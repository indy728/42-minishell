/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:33:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/06/29 01:08:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cat_strings(char *str, int i, char *arg)
{
	char	*new;
	int		j;

	j = 0;
	while (!ft_iswhitespace((str + i)[j]))
		++j;
	new = ft_strndup(str, i - 1);
	new = ft_strmove(ft_strjoin(new, arg), &new);
	new = ft_strmove(ft_strjoin(new, str + i + j), &new);
	return (new);
}

void	handle_variable(char **str, int *i, char **env)
{
	char	*new;
	char	type;
	int		j;
	char	*arg;

	new = *str;
	arg = NULL;
	j = 0;
	type = is_open_quote(new, *i);
	while (!ft_iswhitespace((new + *i + 1)[j]))
		++j;
	if (type == '\'')
		return ;
	else
	{
		if (!(arg = find_args(env, ft_strncpy(arg, new + *i + 1, j))))//arg need to be malloc'd?
			arg = "";
		new = cat_strings(new, *i, arg);
		*i += ft_strlen(arg);
	}
	*str = ft_strmove(new, str);
}

void	handle_escape(char **str, int *i)
{
	char	*new;
	char	type;

	new = *str;
	type = is_open_quote(new, *i);
	if (!type)
		ft_strncpy(new + *i, new + *i + 1, ft_strlen(new + *i + 1) + 1);
	else
		*i += 1;
	*str = ft_strmove(new, str);
}

void	ms_convert_args(char **str, char **env)
{
	char	*str1;
	int		i;

	i = -1;
	str1 = *str;
	while (str1[++i])
	{
		if (str1[i] == '\\')
			handle_escape(&str1, &i);
		else if (str1[i] == '$')
			handle_variable(&str1, &i, env);
	}
	*str = ft_strmove(str1, str);
}
