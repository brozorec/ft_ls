/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/03 12:40:40 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void
	put_dir_name(char *s)
{
	ft_putstr(s);
	ft_putstr(":\n");
}

t_biggest
	*print_blocks_get_biggest(t_cont *list, t_biggest *bist, t_option option)
{
	bist = get_biggest(list, option, 1);
	if (bist->flag_not_hidden == 1)
	{
		ft_putstr("total ");
		ft_putnbr(bist->blocks);
		ft_putstr("\n");
	}
	return (bist);
}

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
		put_dir_name(path);
	if (option.l == 1)
		bist = print_blocks_get_biggest(list, bist, option);
	while (list)
	{
		if (list->name[0] == '.' && option.a == 0)
		{
			list = list->next;
			continue;
		}
		put_attr(list, bist, option);
		list = list->next;
	}
	if (lst->flag == 1)
		lst->counter--;
	free(bist);
}

void
	print_err_file(t_param *lst, t_option option)
{
	int				i;
	int				j;
	t_biggest		*bist;

	i = 0;
	j = 0;
	bist = get_biggest(lst->file, option, 0);
	while (lst->err)
	{
		j++;
		handle_err("ft_ls: ", lst->err->name);
		// perror(lst->err->name);
		lst->err = lst->err->next;
	}
	while (lst->file)
	{
		i++;
		put_attr(lst->file, bist, option);
		lst->file = lst->file->next;
	}
	if (i != 0 && lst->dir)
		ft_putstr("\n");
	if (lst->dir_num > 0 && (i != 0 || j != 0))
		put_dir_name(lst->dir->name);
	free(bist);
}

void
	print(t_param *lst, t_option option)
{
	t_cont		*copy_err;
	t_cont		*copy_file;
	t_cont		*copy_dir;

	copy_err = lst->err;
	copy_file = lst->file;
	copy_dir = lst->dir;
	print_err_file(lst, option);
	while (lst->dir)
	{
		lst->dir_name = ft_strdup(lst->dir->name);
		lst->flag = 1;
		content_dir(lst->dir->name, lst, option);
		lst->dir = (lst->dir)->next;
		free(lst->dir_name);
	}
	lst->err = copy_err;
	lst->file = copy_file;
	lst->dir = copy_dir;
	free_param(lst, option);
}
