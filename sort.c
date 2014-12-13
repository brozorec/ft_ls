/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:01:09 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/13 14:47:10 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	sort(t_cont *list, t_cont *new, t_cont *tmp, long (*f)(void *a, void *b))
{
	while (list)
	{
		if (f(list->val, new->val) >= 0)
		{
			if (tmp == 0)
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

int
	add(t_cont **lst, t_cont *new, long (*f)(void *a, void *b))
{
	t_cont				*head;
	t_cont				*tmp;

	tmp = 0;
	if (*lst == 0)
	{
		*lst = new;
		return (1);
	}
	else
	{
		head = *lst;
		if (sort(*lst, new, tmp, f) == 1)
			*lst = new;
		else
			*lst = head;
	}
	return (1);
}

/*void	print(t_list *list)
{
	ft_putstr(list->content);
	ft_putstr("\n");
}

int		list_content_dir(char *path)
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
	}*/
