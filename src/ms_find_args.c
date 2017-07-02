/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 00:15:24 by kmurray           #+#    #+#             */
/*   Updated: 2017/06/29 00:29:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_args(char **env, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (NULL);
	}
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(ft_tolowerstr(env[i]), ft_tolowerstr(str), ft_strlen(str)))
			return (env[i] + ft_strlen(str) + 1);
	}
	return (NULL);
}
