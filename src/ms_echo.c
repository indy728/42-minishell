/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:58:41 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 01:25:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int nl_flag(char **args)
{
	if (args[1] && !ft_strcmp(args[1], "-n"))
		return (1);
	return (0);
}

void	ms_echo(char **args)
{
	char	nl;
	int		size;
	int		i;

	i = 1;
	nl = nl_flag(args);
	size = ft_size_r(args);
	while (args[i] && !ft_strcmp(args[i], "-n"))
		++i;
	while (i < size - 1)
		ft_printf("%s ", args[i++]);
	nl ? ft_printf("%s%%\n", args[i]) : ft_putendl(args[i]);
}
