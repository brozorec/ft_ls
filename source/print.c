/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/19 17:18:41 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_prototypes.h"

void
	put_dir_name(char *s, t_param *lst)
{
	ft_putstr(s);
	ft_putstr(":\n");
	lst->flag_print = 1;
}

t_biggest
	*print_blocks_get_biggest(t_cont *list, t_biggest *bist, t_option *option)
{
	bist = get_biggest(list, option, 1);
	if (errno == 0 && bist->flag_not_hidden == 1)
	{
		ft_putstr("total ");
		ft_putnbr(bist->blocks);
		ft_putstr("\n");
	}
	return (bist);
}

void
	print_dir_content(char *path, t_cont *list, t_param *lst, t_option *option)
{
	t_biggest		*bist;

	bist = 0;
	if ((lst->flag && lst->flag_print) || lst->file_counter)
		ft_putstr("\n");
	if ((lst->flag && lst->flag_print) || lst->dir_counter > 1 ||
		lst->err_counter || lst->file_counter)
		put_dir_name(path, lst);
	if (option->l == 1 || option->o || option->g)
		bist = print_blocks_get_biggest(list, bist, option);
	while (list)
	{
		if (list->name[0] == '.' && option->a == 0)
		{
			list = list->next;
			continue;
		}
		put_attr(list, lst, bist, option);
		list = list->next;
	}
	free(bist);
}

void
	print_err_file(t_param *lst, t_option *option)
{
	t_biggest		*bist;

	bist = get_biggest(lst->file, option, 0);
	while (lst->err)
	{
		handle_err("ft_ls: ", lst->err->name, option);
		lst->err = lst->err->next;
	}
	while (lst->file)
	{
		put_attr(lst->file, lst, bist, option);
		lst->file = lst->file->next;
	}
	free(bist);
}

void
	print(t_param *lst, t_option *option)
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
		content_dir(lst->dir->name, lst, lst->dir, option);
		lst->dir = (lst->dir)->next;
		free(lst->dir_name);
	}
	lst->err = copy_err;
	lst->file = copy_file;
	lst->dir = copy_dir;
	free_param(lst, *option);
}
