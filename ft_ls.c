/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:01:09 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/02 18:50:55 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			sort(t_list *list, t_list *new, int (*f)(const char *s1, const char *s2))
{
	t_list			*tmp;

	while (list)
	{
		if (f(list->content, new->content) >= 0)
		{
			if (tmp->next == 0)
			{
				new->next = list;
				return (1);
			}
			new->next = list;
			tmp->next = new;
			list = tmp;
			return (0);
		}
		if (list->next == 0)
		{
			list->next = new;
			return (0);
		}
		tmp = list;
		list = list->next;
	}
	return (0);
}

int			add(t_list **list, char *val, int (*f)(const char *s1, const char *s2))
{
	t_list				*new;
	t_list				*head;

	if ((new = ft_listnew(val)) == 0)
		return (0);
	if (*list == 0)
	{	
		*list = new;
		return (1);
	}
	else
	{
		head = *list;
		if (sort(*list, new, f) == 1)
		{
			*list = new;
		}
		else
		{
			*list = head;
		}
	}
	return (1);
}

void	print(t_list *list)
{
	ft_putstr(list->content);
	ft_putstr("\n");
}

int				list_content_dir(char *path)
{
	DIR					*dirp;
	struct dirent		*next_entry;
	t_list				*list;

	list = 0;
	if ((dirp = opendir(path)) == 0)
	{
		perror(ft_strjoin("ls: ", path));
		exit(0);
	}
	errno = 0;
	while ((next_entry = readdir(dirp)) != 0)
	{
		if ((next_entry->d_name)[0] == '.')
			continue;
		add(&list, next_entry->d_name, &ft_strcmp);
	}
	ft_lstiter(list, &print);
	if (errno != 0)
		perror("readdir");
	return (0);
}
