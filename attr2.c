/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:14:02 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/17 11:34:10 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_links(long link, int biggest)
{
	int				siz;
	int				i;

	siz = ft_getsize_nbr((void *)link);
	i = biggest - siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(link);
	ft_putchar(' ');
}

void		file_user(long user, int biggest)
{
	int				siz;
	int				i;
	struct passwd	*new_uid;

	new_uid = 0;
	new_uid = getpwuid(user);
	if (new_uid == 0 || new_uid->pw_name == 0)
		ft_putnbr(user);
	else
	{
		ft_putstr(new_uid->pw_name);
		siz = ft_strlen(new_uid->pw_name);
		i = biggest - siz + 2;
	}
	while (i > 0)
	{
		ft_putstr(" ");
		i--;
	}
}

void		file_group(long group, int biggest)
{
	int				siz;
	int				i;
	struct group	*new_gid;

	new_gid = 0;
	new_gid = getgrgid(group);
	if (new_gid == 0 || new_gid->gr_name == 0)
		ft_putnbr(group);
	else
	{
		ft_putstr(new_gid->gr_name);
		siz = ft_strlen(new_gid->gr_name);
		i = biggest - siz;
	}
	while (i > 0)
	{
		ft_putstr(" ");
		i--;
	}
}

void		file_size(long long size, int biggest)
{
	int			siz;
	int			i;

	siz = ft_getsize_nbr((void *)size);
	i = biggest - siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(size);
	ft_putchar(' ');
}

void		file_devices(long dev)
{
	int			siz;
	int			i;

	siz = ft_getsize_nbr((void *)dev);
	i = siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(dev);
	ft_putchar(' ');
}
