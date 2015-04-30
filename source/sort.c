/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:01:09 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/10 17:02:56 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_prototypes.h"

int
	case_greater(t_cont **list, t_cont **new, t_cont **tmp)
{
	if (*tmp == 0)
	{
		(*new)->next = *list;
		return (1);
	}
	(*new)->next = *list;
	(*tmp)->next = *new;
	list = tmp;
	return (0);
}

int
	t(t_cont **list, t_cont **new, t_cont **tmp, long (*f)(void *a, void *b))
{
	while (*list && (*list)->val == (*new)->val)
	{
		if (f((*list)->name, (*new)->name) >= 0)
		{
			if (case_greater(list, new, tmp) == 1)
				return (1);
			return (0);
		}
		if ((*list)->next == 0 || (*list)->next->val != (*new)->val)
		{
			(*new)->next = (*list)->next;
			(*list)->next = *new;
			return (0);
		}
		*tmp = *list;
		*list = (*list)->next;
	}
	return (0);
}

int
	no_t(t_cont **list, t_cont **new, t_cont **tmp, long (*f)(void *a, void *b))
{
	while (*list && ft_strcmp((*list)->val, (*new)->val) == 0)
	{
		if (f((void *)(*list)->mtime, (void *)(*new)->mtime) >= 0)
		{
			if (case_greater(list, new, tmp) == 1)
				return (1);
			return (0);
		}
		if ((*list)->next == 0 || ft_strcmp((*list)->next->val, (*new)->val))
		{
			(*new)->next = (*list)->next;
			(*list)->next = *new;
			return (0);
		}
		*tmp = *list;
		*list = (*list)->next;
	}
	return (0);
}

int
	new_sort(t_cont **list, t_cont **new, t_cont **tmp, t_option option)
{
	if (option.t == 0 && option.r == 0)
	{
		if (no_t(list, new, tmp, &ft_numcmp_rev) == 1)
			return (1);
		return (0);
	}
	if (option.t == 0 && option.r == 1)
	{
		if (no_t(list, new, tmp, &ft_numcmp) == 1)
			return (1);
		return (0);
	}
	if (option.t == 1 && option.r == 0)
	{
		if (t(list, new, tmp, &ft_strcmp) == 1)
			return (1);
		return (0);
	}
	if (option.t == 1 && option.r == 1)
	{
		if (t(list, new, tmp, &ft_strcmp_rev) == 1)
			return (1);
		return (0);
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
			if (new_sort(&list, &new, &tmp, o) == 1)
				return (1);
			return (0);
		}
		else if (f(list->val, new->val) > 0)
		{
			if (case_greater(&list, &new, &tmp) == 1)
				return (1);
			return (0);
		}
		tmp = list;
		list = list->next;
	}
	list = tmp;
	list->next = new;
	return (0);
}
