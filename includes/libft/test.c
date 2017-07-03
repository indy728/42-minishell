/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:28:59 by kmurray           #+#    #+#             */
/*   Updated: 2017/07/02 16:11:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
	char	*arr[ac + 1];
	char	**dup;
	char	**grow;
	int		i;

	i = -1;
	while (++i < ac)
		arr[i] = ft_strdup(av[i]);
	arr[i] = NULL;
	ft_print_r(arr);
	dup = ft_dup_r(arr);
	grow = ft_dupn_r(dup, ft_size_r(dup) + 1);
	dup[ft_size_r(dup)] = ft_strdup("six");
	dup[ft_size_r(dup) + 1] = ft_strdup("seven");
	grow[ft_size_r(grow)] = ft_strdup("six");
//	grow[ft_size_r(grow)] = ft_strdup("seven");
//	ft_print_r(dup);
//	ft_del_r(dup);
	ft_print_r(grow);
	ft_del_r(grow);
	return(0);
}
