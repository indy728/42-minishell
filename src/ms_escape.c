/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:06:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 15:07:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		escape(char *str, int i)
{
	if (i && str[i - 1] == '\\')
		return (1);
	return (0);
}

char	is_open_quote(char *str, int pos)
{
	int		quote;
	char	type;
	int	i;

	i = -1;
	quote = 0;
	while (++i < pos && str[i])
	{
		if (!quote && (str[i] == '"' || str[i] == '\'') && !escape(str, i))
		{
			++quote;
			type = str[i];
		}
		else if (quote && str[i] == type && !escape(str, i))
			--quote;
	}
	if (quote)
		return (type);
	return (0);
}

char	is_escaped(char *str, int i)
{
	if (escape(str, i) || is_open_quote(str, i))
		return (1);
	return (0);
}
