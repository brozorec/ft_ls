/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/13 17:31:37 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir_content(t_cont *list)
{
	while (list)
	{
		ft_putstr(list->name);
		ft_putstr("\n");
		list = list->next;
	}
}

void		print(t_cont_params lst, t_option option)
{
	int			i;
	t_cont		*params_err;
	t_cont		*params_file;
	t_cont		*params_dir;

	params_err = lst.err;
	params_file = lst.file;
	params_dir = lst.dir;
	i = 0;
	while (params_err)
	{
		ft_putstr(params_err->name);
		ft_putstr("\n");
		params_err = params_err->next;
	}
	while (params_file)
	{
		i++;
		ft_putstr(params_file->name);
		ft_putstr("\n");
		params_file = params_file->next;
	}
	if (i != 0 && params_dir)
		ft_putstr("\n");
	while (params_dir)
	{
		ft_putstr(ft_strjoin(params_dir->name, ":\n"));
		content_dir(params_dir->name, option);
		params_dir = params_dir->next;
	}
}
