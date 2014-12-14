/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:30:11 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/13 19:09:59 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	collect_content_dir(char *name, char *path, t_cont **lst, t_option option)
{
	t_cont				*new;

	new = 0;
	detect_type(name, path, &new, option);
	fill_list(lst, new, option);
}

int		dir_tree(char *path, t_cont *list, t_option option)
{
	while (list)
	{
		if (S_ISDIR(list->mode))
		{
		  content_dir(path, option);
		}
		list = list->next;
	}
	if (option.a == 1)
		ft_putstr("op a");
	return (0);
}

int		content_dir(char *path, t_option option)
{
	DIR					*dirp;
	struct dirent		*next_entry;
	t_cont				*list;

	list = 0;
	dirp = 0;
	next_entry = 0;
	if ((dirp = opendir(path)) == 0)
	{
		perror(ft_strjoin("ls: ", path));
		exit(0);
	}
	errno = 0;
	while ((next_entry = readdir(dirp)) != 0)
	{
		if ((next_entry->d_name)[0] == '.' && option.a == 0)
			continue;
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, next_entry->d_name);
		collect_content_dir(next_entry->d_name, path, &list, option);
	}
	print_dir_content(list);
	closedir(dirp);
//	if (errno != 0)
//		perror("readdir");
	if (option.recursive == 1)
		dir_tree(path, list, option);
	return (0);
}
