/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 13:36:19 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 20:21:34 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_biggest_link(t_cont *list, t_option option, int flag_i_am_dir)
{
	int			i;
	int			siz;

	i = 0;
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		siz = ft_getsize_nbr(list->nlink);
		if (siz > i)
			i = siz;
		list = list->next;
	}
	return (i);
}

int 			check_if_dev(t_cont *list, t_option option, int flag_i_am_dir)
{
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		if (S_ISCHR(list->mode) || S_ISBLK(list->mode))
			return (1);
		list = list->next;
	}
	return (0);
}

int 			check_if_big(t_cont *list, t_option option, int flag_i_am_dir)
{
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0 && flag_i_am_dir == 1)
		{
			list = list->next;
			continue;
		}
		if (ft_getsize_nbr(list->size) >= 8)
			return (1);
		list = list->next;
	}
	return (0);
}

t_biggest		*bist_init(t_biggest *bist)
{
	bist = (t_biggest *)malloc(sizeof(t_biggest *));
	bist->link_biggest = 0;
	bist->size_biggest = 0;
	bist->uid_biggest = 0;
	bist->gid_biggest = 0;
	bist->date_biggest = 0;
	bist->flag_year = 0;
	bist->flag_there_is_dev = 0;
	bist->flag_big_file = 0;
	return (bist);
}

t_biggest		*get_biggest(t_cont *list, t_option option, int flag_i_am_dir)
{
	t_biggest		*bist;

	if (list == 0)
		return (0);
	bist = 0;
	bist = bist_init(bist);
	bist->link_biggest = get_biggest_link(list, option, flag_i_am_dir);
	bist->size_biggest = get_biggest_size(list, option, flag_i_am_dir);
	bist->uid_biggest = get_biggest_uid(list, option, flag_i_am_dir);
	bist->gid_biggest = get_biggest_gid(list, option, flag_i_am_dir);
	bist->flag_year = get_year_flag(list, option, flag_i_am_dir);
	bist->date_biggest = get_biggest_date(list, option, flag_i_am_dir);
	bist->flag_there_is_dev = check_if_dev(list, option, flag_i_am_dir);
	bist->flag_big_file = check_if_big(list, option, flag_i_am_dir);
	// printf("%d\n", bist->size_biggest);
	// printf("%d\n", bist->flag_there_is_dev);
	return (bist);
}
