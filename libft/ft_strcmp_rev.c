/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:18:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/01 13:42:50 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_rev(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s2[i] - (unsigned char)s1[i]);
		i++;
	}
	return ((unsigned char)s2[i] - (unsigned char)s1[i]);
}
