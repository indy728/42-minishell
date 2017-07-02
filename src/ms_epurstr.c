/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:22:21 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 21:58:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*all_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_iswhitespace(str[i]) && !is_escaped(str, i))
			str[i] = ' ';
	}
	return (str);
}

int		extra_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = all_spaces(str);
	while (str[i] && str[i] == ' ')
		++i;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == ' ' && !is_escaped(str, i))
			++i;
		else
		{
			++j;
			++i;
		}
	}
	if (i > 0 && str[i - 1] == ' ')
		--j;
	return (j);
}

char	*ms_epurstr(char *str)
{
	int		shorten;
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = -1;
	shorten = extra_spaces(str);
	dup = ft_strnew(shorten + 1);
	while (ft_iswhitespace(str[i]))
		++i;
	while (++j < shorten)
	{
		dup[j] = str[i++];
		while (str[i - 1] == ' ' && str[i] == ' ' && !is_escaped(str, i))
			++i;
	}
	dup[j] = '\0';
	return (dup);
}
