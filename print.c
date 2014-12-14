/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/14 18:10:35 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir_content(char *path, t_cont *list, t_param lst, t_option option)
{
	if (lst.dir_num > 1)
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
	lst.dir_num--;
	ft_putnbr(lst.dir_num);
	if (lst.dir_num > 0)
	  ft_putstr("\n");
}

void		print_err_file(t_param list, t_option option)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (list.err)
	{
		j++;
		ft_putstr(list.err->name);
		ft_putstr("\n");
		list.err = list.err->next;
	}
	while (list.file)
	{
		i++;
		if (option.l == 1)
			get_attr(list.file);
		ft_putstr(list.file->name);
		ft_putstr("\n");
		list.file = list.file->next;
	}
	if (i != 0 && list.dir)
		ft_putstr("\n");
	if (list.dir_num == 1 && (i != 0 || j != 0))
		ft_putstr(ft_strjoin(list.dir->name, ":\n"));
}

void		print(t_param lst, t_option option)
{
  //	print_err_file(lst, option);
	while (lst.dir)
	{
		content_dir(lst.dir->name, lst, option);
		lst.dir = lst.dir->next;
	}
}
