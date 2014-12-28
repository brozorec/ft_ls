/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/17 11:30:54 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_year_flag(t_cont *list)
{
	int			flag1;
	int			flag2;

	flag1 = 0;
	flag2 = 0;
	while(list)
	{
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

void		attr_perm_link_group_siz_dev(t_cont *list)
{
	int			link_biggest;
	int			size_biggest;
	int			uid_biggest;
	int			gid_biggest;

	link_biggest = get_biggest_link(list);
	size_biggest = get_biggest_size(list);
	uid_biggest = get_biggest_uid(list);
	gid_biggest = get_biggest_gid(list);
	file_type(list->mode);
	file_perm_first(list->mode);
	file_perm_second(list->mode);
	file_links(list->nlink, link_biggest);
	file_user(list->uid, uid_biggest);
	file_group(list->gid, gid_biggest);
	if (S_ISCHR(list->mode) || S_ISBLK(list->mode))
		file_devices(list->rdev);
	else
		file_size(list->size, size_biggest);
}

void		get_symlink(char *link_path)
{
	ssize_t		num_bytes;
	char		buf[4096];

	num_bytes = readlink(link_path, buf, 4095);
	buf[num_bytes] = '\0';
	if (num_bytes == -1)
		handle_err("readlink");
	ft_putstr(buf);
}

void		get_attr(t_cont *list, t_option option)
{
	int			year_flag;
	size_t		date_biggest;
	
	year_flag = get_year_flag(list);
	date_biggest = get_biggest_date(list);
	while (list)
	{
		if (option.l == 1)
		{
			attr_perm_link_group_siz_dev(list);
			file_time(list->mtime, year_flag, date_biggest);
		}
		ft_putstr(list->name);
		if (option.l == 1 && S_ISLNK(list->mode))
		{
			ft_putstr(" -> ");
			get_symlink(list->path);
		}
		ft_putstr("\n");
		list = list->next;
	}
}
