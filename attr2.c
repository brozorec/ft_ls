/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:14:02 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/19 17:12:52 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_prototypes.h"

void		file_user(long user, t_biggest *bist)
{
	int				siz;
	int				i;
	struct passwd	*new_uid;

	new_uid = 0;
	new_uid = getpwuid(user);
	i = 0;
	if (new_uid == 0 || new_uid->pw_name == 0)
	{
		ft_putnbr(user);
		siz = ft_getsize_nbr(user);
		i = bist->uid_biggest - siz + 2;
	}
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
	{
		ft_putnbr(group);
		siz = ft_getsize_nbr(group);
		i = bist->gid_biggest - siz + 2;
	}
	else
	{
		ft_putstr(new_gid->gr_name);
		siz = ft_strlen(new_gid->gr_name);
		i = bist->gid_biggest - siz + 2;
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
	i = bist->size_biggest - siz;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (bist->flag_there_is_dev == 1 && bist->flag_big_file == 1)
	{
		i = bist->size_biggest - 8;
		while (i > 0)
		{
			ft_putstr(" ");
			i--;
		}
	}
	ft_putnbr(size);
	ft_putchar(' ');
}

void		put_spaces(int i)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void		file_devices(long dev)
{
	int			siz;
	int			i;

	i = 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	siz = ft_getsize_nbr(major(dev));
	i = 3 - siz;
	put_spaces(i);
	ft_putnbr(major(dev));
	ft_putstr(",");
	siz = ft_getsize_nbr(minor(dev));
	i = 4 - siz;
	put_spaces(i);
	ft_putnbr(minor(dev));
	ft_putchar(' ');
}
