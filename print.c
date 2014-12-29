/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 18:09:43 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	print_dir_content(char *path, t_cont *list, t_param *lst, t_option option)
{
	t_biggest		*bist;

	bist = 0;
	if (lst->dir_num != 1 && lst->counter != lst->dir_num)
		ft_putstr("\n");
	else if (lst->flag == 0)
		ft_putstr("\n");
	if (lst->dir_num > 1 || lst->flag == 0)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (option.l == 1)
		bist = get_biggest(list, option, 1);
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0)
		{
			list = list->next;
			continue;
		}
		get_attr(list, bist, option);
		list = list->next;
	}
	if (lst->flag == 1)
		lst->counter--;
}

void
	print_err_file(t_param *lst, t_option option)
{
	int				i;
	int				j;
	t_biggest		*bist;

	i = 0;
	j = 0;
	bist = 0;
	bist = get_biggest(lst->file, option, 0);
	while (lst->err)
	{
		j++;
		handle_err(ft_strjoin("ls: ", lst->err->name));
		handle_err(": No such file or directory\n");
		lst->err = lst->err->next;
	}
	while (lst->file)
	{
		i++;
		get_attr(lst->file, bist, option);
		lst->file = lst->file->next;
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
