/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:40:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/03 13:51:50 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlnstr(char const *big, char const *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i++] == little[j++])
		{
			if (little[j] == '\0')
				return (i);
		}
		i++;
	}
	if (*little == '\0')
		return (ft_strlen(big));
	return (-1);
}
