/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 13:59:59 by bbarakov         ###   ########.fr       */
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

void		file_perm_first(unsigned long mode)
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
		write(1, "x", 1);
	else
		write(1, "-", 1);
	if (mode & S_IRGRP)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (mode & S_IWGRP)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (mode & S_IXGRP)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void		file_perm_second(unsigned long mode)
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
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void		file_links(long link, t_biggest *bist)
{
	int				siz;
	int				i;

	siz = ft_getsize_nbr(link);
	i = bist->link_biggest - siz + 2;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putnbr(link);
	ft_putchar(' ');
}
