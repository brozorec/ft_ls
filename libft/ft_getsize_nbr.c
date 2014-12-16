/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getsize_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 15:10:07 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/16 15:27:39 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_getsize_nbr(void *nbr)
{
	int			i;
	long long	n;

	i = 1;
	n = (long long)nbr;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
