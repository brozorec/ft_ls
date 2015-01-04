/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/04 19:21:40 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			attr_perm_link_group_siz_dev_time(t_cont *list, t_biggest *bist)
{
	int 		xattr;
	int 		acl;

	file_type(list->mode);
	file_perm_user(list->mode);
	file_perm_group(list->mode);
	file_perm_others(list->mode);
	xattr = file_xattr(list->path);
	acl = file_acl(list->path);
	file_links(list->nlink, bist, xattr, acl);
	file_user(list->uid, bist);
	file_group(list->gid, bist);
	if (S_ISCHR(list->mode) || S_ISBLK(list->mode))
		file_devices(list->rdev);
	else
		file_size(list->size, bist);
	file_time(list->mtime);
	return (xattr);
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
	int 		xattr;

	xattr = 0;
	if (option.l == 1)
	{
		xattr = attr_perm_link_group_siz_dev_time(list, bist);
	}
	ft_putstr(list->name);
	if (option.l == 1 && S_ISLNK(list->mode))
	{
		ft_putstr(" -> ");
		put_symlink(list->path);
	}
	ft_putstr("\n");
	if (xattr > 0 && option.attr == 1 && option.l == 1)
		put_xattr(list->path, xattr);
	// if (option.acl == 1 && option.l == 1)
		// put_acl(list->path);
}
