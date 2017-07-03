/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:40:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/03 13:47:39 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlstr(char const *big, char const *little)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*b1;

	i = 0;
	b1 = (char *)big;
	while (b1[i])
	{
		j = 0;
		k = i;
		while (b1[i] == little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return (k);
		}
		i = k;
		i++;
	}
	if (*little == '\0')
		return (0);
	return (-1);
}
