/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/04 17:38:56 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_type(unsigned long mode)
{
	if (S_ISREG(mode))
		write(1, "-", 1);
	else if (S_ISDIR(mode))
		write(1, "d", 1);
	else if (S_ISCHR(mode))
		write(1, "c", 1);
	else if (S_ISBLK(mode))
		write(1, "b", 1);
	else if (S_ISFIFO(mode))
		write(1, "p", 1);
	else if (S_ISSOCK(mode))
		write(1, "s", 1);
	else if (S_ISLNK(mode))
		write(1, "l", 1);
}

void		file_perm_user(unsigned long mode)
{
	if (mode & S_IRUSR)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWUSR)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_IXUSR)
	{
		if (mode & S_ISUID)
			write(1, "s", 1);
		else
			write(1, "x", 1);
	}
	else
	{
		if (mode & S_ISUID)
			write(1, "S", 1);
		else
			write(1, "-", 1);
	}

}

void		file_perm_group(unsigned long mode)
{
	if (mode & S_IRGRP)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWGRP)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_IXGRP)
	{
		if (mode & S_ISGID)
			write(1, "s", 1);
		else
			write(1, "x", 1);
	}
	else
	{
		if (mode & S_ISGID)
			write(1, "S", 1);
		else
			write(1, "-", 1);
	}
}

void		file_perm_others(unsigned long mode)
{
	if (mode & S_IROTH)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWOTH)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_IXOTH)
	{
		if (mode & S_ISVTX)
			write(1, "t", 1);
		else
			write(1, "x", 1);
	}
	else
	{
		if (mode & S_ISVTX)
			write(1, "T", 1);
		else
			write(1, "-", 1);
	}
}

void		file_links(long link, t_biggest *bist, int xattr, int acl)
{
	int				siz;
	int				i;

	siz = ft_getsize_nbr(link);
	i = bist->link_biggest - siz + 2;
	if (xattr > 0)
	{
		i--;
		ft_putchar('@');
	}
	else if (acl > 0)
	{
		i--;
		ft_putchar('+');
	}
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(link);
	ft_putchar(' ');
}
