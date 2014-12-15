/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/15 20:16:56 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir_content(t_cont *list, t_param *lst, t_option option, int i)
{
	if (lst->dir_num > 0 && i != 1)
		ft_putstr(ft_strjoin(list->addr, ":\n"));
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0)
		{
			list = list->next;
			continue;
		}
		ft_putstr(list->name);
		ft_putstr("\n");
		list = list->next;
	}
	lst->dir_num--;
	if (lst->dir_num > 0)
	  ft_putstr("\n");
}

void		print_err_file(t_param *lst, t_option option)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (lst->err)
	{
		j++;
		ft_putstr(lst->err->name);
		ft_putstr("\n");
		lst->err = lst->err->next;
	}
	while (lst->file)
	{
		i++;
		if (option.l == 1)
			get_attr(lst->file);
		ft_putstr(lst->file->name);
		ft_putstr("\n");
		lst->file = lst->file->next;
	}
	if (i != 0 && lst->dir)
		ft_putstr("\n");
	if (lst->dir && (i != 0 || j != 0))
		ft_putstr(ft_strjoin(lst->dir->name, ":\n"));
}

void		print(t_param *lst, t_option option)
{
	t_cont		*list;

	print_err_file(lst, option);
	while (lst->dir)
	{
		list = content_dir(lst->dir->name, lst, option);
		print_dir_content(list, lst, option, lst->dir->level);
		lst->dir = lst->dir->next;
	}
}
