/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:14:02 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 20:15:09 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_user(long user, t_biggest *bist)
{
	int				siz;
	int				i;
	struct passwd	*new_uid;

	new_uid = 0;
	new_uid = getpwuid(user);
	i = 0;
	if (new_uid == 0 || new_uid->pw_name == 0)
		ft_putnbr(user);
	else
	{
		ft_putstr(new_uid->pw_name);
		siz = ft_strlen(new_uid->pw_name);
		i = bist->uid_biggest - siz + 2;
	}
	while (i > 0)
	{
		ft_putstr(" ");
		i--;
	}
}

void		file_group(long group, t_biggest *bist)
{
	int				siz;
	int				i;
	struct group	*new_gid;

	new_gid = 0;
	new_gid = getgrgid(group);
	i = 0;
	if (new_gid == 0 || new_gid->gr_name == 0)
		ft_putnbr(group);
	else
	{
		ft_putstr(new_gid->gr_name);
		siz = ft_strlen(new_gid->gr_name);
		i = bist->gid_biggest - siz;
	}
	while (i > 0)
	{
		ft_putstr(" ");
		i--;
	}
}

void		file_size(long long size, t_biggest *bist)
{
	int			siz;
	int			i;

	siz = ft_getsize_nbr(size);
	i = bist->size_biggest - siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (bist->flag_there_is_dev == 1 && bist->flag_big_file == 1)
		ft_putstr("  ");
	ft_putnbr(size);
	ft_putchar(' ');
}

void		file_devices(long dev, t_biggest *bist)
{
	int			siz;
	int			i;
	int 		siz_dev;
	int			j;

	siz = ft_getsize_nbr(dev);
	i = bist->size_biggest - siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	siz_dev = ft_getsize_nbr(major(dev));
	j = 2 - siz_dev;
	while (j > 0)
	{
		ft_putchar(' ');
		j--;
	}
	ft_putnbr(major(dev));
	ft_putstr(",");
	siz_dev = ft_getsize_nbr(minor(dev));
	j = 4 - siz_dev;
	while (j > 0)
	{
		ft_putchar(' ');
		j--;
	}
	ft_putnbr(minor(dev));
	ft_putchar(' ');
}
