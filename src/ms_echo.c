/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 20:58:41 by kmurray           #+#    #+#             */
/*   Updated: 2017/06/24 22:11:35 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int nl_flag(char *line)
{
	if (!ft_strcmp(line, "-n") || !ft_strncmp(line, "-n ", 3))
		return (1);
	return (0);
}

int		count_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		++i;
	return (i);
}

void	ms_echo(char *line)
{
	char	*echo;
	char	nl;

	nl = nl_flag(line);
	echo = nl ? line + 2 + count_empty(line + 2) : line;
	nl ? ft_putstr(echo) : ft_putendl(echo);
}
