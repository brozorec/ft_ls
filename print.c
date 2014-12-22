/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/22 19:34:28 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	print_dir_content(char *path, t_cont *list, t_param *lst, t_option option)
{
	if (lst->dir_num != 1 && lst->counter != lst->dir_num)
		ft_putstr("\n");
	else if (lst->flag == 0)
		ft_putstr("\n");
	if (lst->dir_num > 1 || lst->flag == 0)
		ft_putstr(ft_strjoin(path, ":\n"));
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
	if (lst->flag == 1)
		lst->counter--;
}

void
	print_err_file(t_param *lst, t_option option)
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
	if (lst->file)
	{
		i++;
		get_attr(lst->file, option);
	}
	if (i != 0 && lst->dir)
		ft_putstr("\n");
	if (lst->dir_num > 0 && (i != 0 || j != 0))
		ft_putstr(ft_strjoin(lst->dir->name, ":\n"));
}

void
	print(t_param *lst, t_option option)
{
	print_err_file(lst, option);
	while (lst->dir)
	{
		lst->dir_name = ft_strdup(lst->dir->name);
		lst->flag = 1;
		content_dir(lst->dir->name, lst, option);
		lst->dir = (lst->dir)->next;
	}
}
