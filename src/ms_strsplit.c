/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 01:08:46 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 18:47:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ms_count_args(char *str, char c)
{
	int	i;
	int	n;

	i = -1;
	n = str ? 1 : 0;
	while (str[++i])
	{
		if (str[i] == c && !is_escaped(str, i))
			++n;
	}
	return (n);
}

int		ms_arglen(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c && !is_escaped(str, i))
			break ;
	}
	return (i);
}

char	**ms_strsplit(char *str, char c)
{
	int		cw;
	int		i;
	int		n;
	int		wl;
	char	**split;

	i = -1;
	n = 0;
//	if (!str)
//		return (NULL);
	cw = ms_count_args(str, c);
	if (!(split = (char **)malloc((sizeof(char *) * (cw + 1)))))
		return (NULL);
	while (++i < cw)
	{
		while (str[n] == c && !is_escaped(str, n))
			++n;
		wl = ms_arglen(str + n, c);
		if (!(split[i] = ft_strsub(str, n, wl)))
		{
			split[i] = NULL;
			ft_del_r(split);
			return (NULL);
		}
		n += wl;
	}
	split[i] = NULL;
	return (split);
}
