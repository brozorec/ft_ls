/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:54:32 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/05 14:39:09 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	cont_init(t_cont **new, struct stat *buf)
{
	(*new)->mode = buf->st_mode;
	(*new)->nlink = buf->st_nlink;
	(*new)->uid = buf->st_uid;
	(*new)->gid = buf->st_gid;
	(*new)->rdev = buf->st_rdev;
	(*new)->size = buf->st_size;
	(*new)->blocks = buf->st_blocks;
	(*new)->mtime = buf->st_mtime;
	(*new)->flag_is_param = 0;
}

t_cont
	*create_new(char *name, t_cont *new, struct stat *buf, t_option option)
{
	if ((new = (t_cont *)malloc(sizeof(t_cont))) == 0)
		handle_err("ft_ls: ", "malloc");
	if (buf != 0)
		cont_init(&new, buf);
	new->name = ft_strdup(name);
	new->next = 0;
	if (option.t == 0 || buf == 0)
	{
		if ((new->val = (char *)malloc(ft_strlen(name) + 1)) == 0)
			handle_err_eacces("ft_ls: ", "malloc");
		ft_memcpy(new->val, name, ft_strlen(name) + 1);
	}
	else
		new->val = (void *)new->mtime;
	return (new);
}

int
	detect_type(char *name, char *path, t_cont **new, t_option option)
{
	struct stat			buf;
	int					i;

	i = lstat(path, &buf);
	if (option.l == 0 && !S_ISLNK(buf.st_mode))
		i = stat(path, &buf);
	if (errno && errno != 2)
	{
		if (name[0] != '.' || option.a != 0)
			handle_err_eacces("ft_ls: ", ft_strrchr(path, '/') + 1);
		return (-1);
	}
	if (i == -1)
	{
		*new = create_new(name, *new, 0, option);
		(*new)->path = ft_strdup(path);
		return (0);
	}
	*new = create_new(name, *new, &buf, option);
	(*new)->path = ft_strdup(path);
	if (S_ISDIR(buf.st_mode))
		return (2);
	return (1);
}

int
	add(t_cont **list, t_cont *new, t_option o, long (*f)(void *a, void *b))
{
	t_cont				*head;

	if (*list == 0)
	{
		*list = new;
		return (1);
	}
	else if (new->flag_is_param == 0)
	{
		head = *list;
		if (sort(*list, new, o, f) == 1)
			*list = new;
		else
			*list = head;
	}
	else if (new->flag_is_param == 1)
	{
		head = *list;
		if (sort_pm(*list, new, f) == 1)
			*list = new;
		else
			*list = head;
	}
	return (1);
}

int
	fill_list(t_cont **lst, t_cont *new, t_option option)
{
	if (option.t == 0 && option.r == 0)
		add(lst, new, option, &ft_strcmp);
	else if (option.t == 1 && option.r == 1)
		add(lst, new, option, &ft_numcmp);
	else if (option.t == 1 && option.r == 0)
		add(lst, new, option, &ft_numcmp_rev);
	else if (option.t == 0 && option.r == 1)
		add(lst, new, option, &ft_strcmp_rev);
	return (0);
}
