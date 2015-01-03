/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/03 11:35:49 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		attr_perm_link_group_siz_dev_time(t_cont *list, t_biggest *bist)
{
	file_type(list->mode);
	file_perm_first(list->mode);
	file_perm_second(list->mode);
	file_links(list->nlink, bist);
	file_user(list->uid, bist);
	file_group(list->gid, bist);
	if (S_ISCHR(list->mode) || S_ISBLK(list->mode))
		file_devices(list->rdev);
	else
		file_size(list->size, bist);
	file_time(list->mtime);
}

void		put_symlink(char *link_path)
{
	ssize_t		num_bytes;
	char		buf[4096];

	num_bytes = readlink(link_path, buf, 4095);
	buf[num_bytes] = '\0';
	if (num_bytes == -1)
		handle_err("ft_ls: ", link_path);
	ft_putstr(buf);
}

void		put_attr(t_cont *list, t_biggest *bist, t_option option)
{
	if (option.l == 1)
	{
		attr_perm_link_group_siz_dev_time(list, bist);
	}
	ft_putstr(list->name);
	if (option.l == 1 && S_ISLNK(list->mode))
	{
		ft_putstr(" -> ");
		put_symlink(list->path);
	}
	ft_putstr("\n");
}
