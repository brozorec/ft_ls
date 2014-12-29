/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 20:08:59 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int			get_biggest_size(t_cont *list, t_option option, int flag_i_am_dir)
{
	int			i;
	int			siz;
	int			dev;

	i = 0;
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		siz = ft_getsize_nbr(list->size);
		dev = ft_getsize_nbr(list->rdev);
		if (siz > i)
			i = siz;
		if (dev > i)
			i = dev;
		list = list->next;
	}
	return (i);
}

int			get_biggest_gid(t_cont *list, t_option option, int flag_i_am_dir)
{
	struct group	*new;
	int				i;
	int				siz;

	i = 0;
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		new = 0;
		new = getgrgid(list->gid);
		siz = ft_strlen(new->gr_name);
		if (siz > i)
			i = siz;
		list = list->next;
	}
	return (i);
}

int			get_biggest_uid(t_cont *list, t_option option, int flag_i_am_dir)
{
	struct passwd	*new;
	int				i;
	int				siz;

	i = 0;
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		new = 0;
		new = getpwuid(list->uid);
		siz = ft_strlen(new->pw_name);
		if (siz > i)
			i = siz;
		list = list->next;
	}
	return (i);
}

int			get_year_flag(t_cont *list, t_option option, int flag_i_am_dir)
{
	int			flag1;
	int			flag2;

	flag1 = 0;
	flag2 = 0;
	while(list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		if (time(0) - 15778463 > list->mtime || list->mtime > time(0))
			flag1 = 1;
		else
			flag2 = 1;
		list = list->next;
	}
	if (flag1 == 1 && flag2 == 1)
		return (1);
	return (0);
}

int			get_biggest_date(t_cont *list, t_option option, int flag_i_am_dir)
{
	int			i;
	int			siz;
	char		**tab;

	i = 0;
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		tab = 0;
		tab = ft_strsplit(ctime(&list->mtime), ' ');
		siz = ft_strlen(tab[2]);
		if (siz > i)
			i = siz;
		list = list->next;
	}
	return (i);
}
