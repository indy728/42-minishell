/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:28:59 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/01 16:06:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
	char	*arr[ac + 1];
	char	**dup;
	int		i;

	i = -1;
	while (++i < ac)
		arr[i] = ft_strdup(av[i]);
	arr[i] = NULL;
	ft_print_r(arr);
	dup = ft_dup_r(arr);
	ft_print_r(dup);
	ft_del_r(dup);
	return(0);
}
