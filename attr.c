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

void		get_attr(t_cont *list, t_option option)
{
	t_cont		*copy;
	int			link_biggest;
	int			size_biggest;
	int			uid_biggest;
	int			gid_biggest;

	copy = list;
	link_biggest = get_biggest_link(copy);
	size_biggest = get_biggest_size(copy);
	uid_biggest = get_biggest_uid(copy);
	gid_biggest = get_biggest_gid(copy);
	while (list)
	{
		if (option.l == 1)
		{
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
		ft_putstr(ft_strjoin(list->name, "\n"));
		list = list->next;
	}
}
