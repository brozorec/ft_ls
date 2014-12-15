/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:30:11 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/15 20:10:16 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	collect_content_dir(char *name, char *path, t_cont **list, t_option option)
{
	t_cont				*new;
	char				*path_to_send;

	new = 0;
	path_to_send = ft_strjoin(path, "/");
	path_to_send = ft_strjoin(path_to_send, name);
	detect_type(name, path_to_send, &new, option);
	free(new->addr);
	new->addr = ft_strdup(path);
	fill_list(list, new, option);
}

int		dir_tree(t_cont *list, t_param *lst, t_option option)
{
	while (list)
	{
		if (ft_strcmp(list->name, ".") == 0 || ft_strcmp(list->name, "..") == 0)
		{
			list = list->next;
			continue;
		}
		if (S_ISDIR(list->mode))
			content_dir(list->path, lst, option);
		list = list->next;
	}
	return (0);
}

t_cont		*content_dir(char *path, t_param *lst, t_option option)
{
	DIR					*dirp;
	struct dirent		*entry;
	t_cont				*list;

	list = 0;
	if ((dirp = opendir(path)) == 0)
	{
		perror(ft_strjoin("ls: ", path));
		exit(0);
	}
	errno = 0;
	while ((entry = readdir(dirp)) != 0)
		collect_content_dir(entry->d_name, path, &list, option);
//	print_dir_content(list, lst, option, );
	closedir(dirp);
	if (errno != 0)
		perror("readdir");
	if (option.recursive == 1)
	{
		if (dir_tree(list, lst, option) == 0)
			free(list);
	}
	return (list);
}
