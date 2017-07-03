/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:07:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 19:22:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_pop_r(char **arr, int n)
{
	char	**dup;
	int		i;

	i = -1;
	if (!(dup = ft_memalloc(sizeof(char *) * (ft_size_r(arr)))))
		return (NULL);
	while (arr[++i])
	{
		if (i == n)
			continue ;
		dup[i] = ft_strdup(arr[i]);
	}
	dup[i] = NULL;
	return (dup);
}
