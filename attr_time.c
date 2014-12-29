/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:53:15 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 13:31:13 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_month_day(char *month, char *day, size_t biggest)
{
	ft_putstr(month);
	ft_putstr(" ");
	if (ft_strlen(day) < biggest)
		ft_putstr(" ");
	ft_putstr(day);
	ft_putstr(" ");
}

void		put_hour(char *h, char *min)
{
	ft_putstr(h);
	ft_putstr(":");
	ft_putstr(min);
}

void		file_time(long mtime, t_biggest *bist)
{
	char	**tab;
	char	**tab_h;
	long	now;

	tab = 0;
	tab_h = 0;
	now = time(0);
	tab = ft_strsplit(ctime(&mtime), ' ');
	tab_h = ft_strsplit(tab[3], ':');
	put_month_day(tab[1], tab[2], bist->date_biggest);
	if (now - 15778463 > mtime || mtime > now)
	{
		if (bist->flag_year == 1)
			ft_putstr(" ");
		tab[4][4] = '\0';
		ft_putstr(tab[4]);
	}
	else
		put_hour(tab_h[0], tab_h[1]);
	ft_putstr(" ");
	// ft_strdel(&str);
	// free(tab);
	// free(tab_h);
}
