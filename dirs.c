/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:30:11 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/30 20:15:46 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	collect_content_dir(char *name, char *path, t_cont **list, t_option option)
{
	t_cont				*new;

	new = 0;
	path = ft_strjoin(path, "/");
	path = ft_strjoin(path, name);
	detect_type(name, path, &new, option);
	fill_list(list, new, option);
}

int
	dir_tree(t_cont *list, t_param *lst, t_option option)
{
	while (list)
	{
		if (ft_strcmp(list->name, ".") == 0 || ft_strcmp(list->name, "..") == 0)
		{
			list = list->next;
			continue;
		}
		if (S_ISDIR(list->mode))
		{
			free(lst->dir_name);
			lst->dir_name = ft_strdup(list->name);
			lst->flag = 0;
			content_dir(list->path, lst, option);
		}
		list = list->next;
	}
	return (0);
}

void
	free_cont(t_cont *list)
{
	while (list)
	{
		free(list->name);
		free(list->path);
		free(list->val);
		list = list->next;
	}
	free(list);
}

t_cont
	*content_dir(char *path, t_param *lst, t_option option)
{
	DIR					*dirp;
	struct dirent		*entry;
	t_cont				*list;

	list = 0;
	if ((dirp = opendir(path)) == 0)
	{
		perror(ft_strjoin("ft_ls: ", path));
		// exit(0);
	}
	errno = 0;
	while (dirp != 0 && (entry = readdir(dirp)) != 0)
		collect_content_dir(entry->d_name, path, &list, option);
	if (lst->flag == 1 || option.a == 1 || (lst->dir_name[0] != '.' && option.a == 0))
		print_dir_content(path, list, lst, option);
	if (dirp != 0)
		closedir(dirp);
	if (errno != 0)
	{
		ft_putstr(list->path);
		ft_putstr("\n");
		perror("readdir");
		exit(0);
	}
	if (option.recursive == 1)
	{
		if (dir_tree(list, lst, option) == 0)
			free_cont(list);
	}
	return (0);
}
