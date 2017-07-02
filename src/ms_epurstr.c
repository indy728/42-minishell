/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:22:21 by kmurray           #+#    #+#             */
/*   Updated: 2017/06/29 01:38:12 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_epurstr(char **str)
{
	int		shorten;
	int		i;
	char	*str1;

	i = 0;
	str1 = *str;
	shorten = ft_strlen(str1) - ft_endspaces(str1);
	while (ft_iswhitespace(str1[i]))
		++i;
	str1 = ft_strsub(str1, i, shorten);
	ft_strmove(str1, str);
}
