/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 00:15:24 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 00:12:45 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_arg(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isalnum(str[i]))
		++i;
	j = -1;
	while (env[++j])
	{
		if (!ft_strncmp(ft_tolowerstr(env[j]), ft_tolowerstr(str), i)
				&& env[j][i] == '=')
			return (ft_strdup(env[j] + i + 1));
	}
	return (NULL);
}
