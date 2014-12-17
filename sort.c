/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:01:09 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/17 17:40:44 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int
	case_greater(t_cont *list, t_cont *new, t_cont *tmp)
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

int
	alpha(t_cont **list, t_cont **new, t_cont **tmp, t_option option)
{
	while (*list && (*list)->val == (*new)->val && option.r == 0)
	{
		if (ft_strcmp((*list)->name, (*new)->name) >= 0)
		{
			if (case_greater(*list, *new, *tmp) == 1)
				return (1);
			return (0);
		}
		if ((*list)->next == 0 || (*list)->next->val != (*new)->val)
		{
			(*new)->next = (*list)->next;
			(*list)->next = *new;
			return (0);
		}
		*list = (*list)->next;
	}
	if (ft_strcmp_rev((*list)->name, (*new)->name) >= 0 && option.r == 1)
	{
		if (case_greater(*list, *new, *tmp) == 1)
			return (1);
	}
	return (0);
}

int
	sort(t_cont *list, t_cont *new, t_option o, long (*f)(void *a, void *b))
{
	t_cont				*tmp;

	tmp = 0;
	while (list)
	{
		if (f(list->val, new->val) == 0)
		{
			if (alpha(&list, &new, &tmp, o) == 1)
				return (1);
			return (0);
		}
		else if (f(list->val, new->val) > 0)
		{
			if (case_greater(list, new, tmp) == 1)
				return (1);
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
	add(t_cont **list, t_cont *new, t_option o, long (*f)(void *a, void *b))
{
	t_cont				*head;

	if (*list == 0)
	{
		*list = new;
		return (1);
	}
	else
	{
		head = *list;
		if (sort(*list, new, o, f) == 1)
			*list = new;
		else
			*list = head;
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
