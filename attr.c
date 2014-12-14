/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:27:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/14 18:19:00 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_type(t_cont *list)
{
	if (S_ISREG(list->mode))
		write(1, "-", 1);
	else if (S_ISDIR(list->mode))
		write(1, "d", 1);
	else if (S_ISCHR(list->mode))
		write(1, "c", 1);
	else if (S_ISBLK(list->mode))
		write(1, "b", 1);
	else if (S_ISFIFO(list->mode))
		write(1, "p", 1);
	else if (S_ISSOCK(list->mode))
		write(1, "s", 1);
	else if (S_ISLNK(list->mode))
		write(1, "l", 1);
}

void		file_perm_first(t_cont *list)
{
	if (list->mode & S_IRUSR)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IWUSR)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IXUSR)
		write(1, "x", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IRGRP)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IWGRP)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IXGRP)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void		file_perm_second(t_cont *list)
{
	if (list->mode & S_IROTH)
		write(1, "r", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IWOTH)
		write(1, "w", 1);
	else
		write(1, "-", 1);
	if (list->mode & S_IXOTH)
		write(1, "x", 1);
	else
		write(1, "-", 1);
}

void		get_attr(t_cont *list)
{
	file_type(list);
	file_perm_first(list);
	file_perm_second(list);
}
