/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/17 11:31:12 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_biggest_gid(t_cont *copy)
{
	struct group	*new;
	int				i;
	int				siz;

	i = 0;
	while (copy)
	{
		new = 0;
		new = getgrgid(copy->gid);
		siz = ft_strlen(new->gr_name);
		if (siz > i)
			i = siz;
		copy = copy->next;
	}
	return (i);
}

int			get_biggest_uid(t_cont *copy)
{
	struct passwd	*new;
	int				i;
	int				siz;

	i = 0;
	while (copy)
	{
		new = 0;
		new = getpwuid(copy->uid);
		siz = ft_strlen(new->pw_name);
		if (siz > i)
			i = siz;
		copy = copy->next;
	}
	return (i);
}

int			get_biggest_link(t_cont *copy)
{
	int			i;
	int			siz;

	i = 0;
	while (copy)
	{
		siz = ft_getsize_nbr(copy->nlink);
		if (siz > i)
			i = siz;
		copy = copy->next;
	}
	return (i);
}

int			get_biggest_size(t_cont *copy)
{
	int			i;
	int			siz;

	i = 0;
	while (copy)
	{
		siz = ft_getsize_nbr(copy->size);
		if (siz > i)
			i = siz;
		copy = copy->next;
	}
	return (i);
}

int			get_biggest_date(t_cont *copy)
{
	int			i;
	int			siz;
	char		**tab;

	i = 0;
	while (copy)
	{
		tab = 0;
		tab = ft_strsplit(ctime(&copy->mtime), ' ');
		siz = ft_strlen(tab[2]);
		if (siz > i)
			i = siz;
		copy = copy->next;
	}
	return (i);
}