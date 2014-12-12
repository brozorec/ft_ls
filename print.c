/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 15:48:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/12 21:23:04 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print(t_cont_params lst, t_option option)
{
//	t_cont       *params_err;
//	t_cont       *params_file;
	t_cont       *params_dir;

//	params_err = 0;
	printf("%s\n", "bebe");
//	params_err = lst.err;
//	params_file = lst.file;
	params_dir = lst.dir;
	if (option.a == 1)
		ft_putstr("option a\n");
	while (params_dir)
	{
		ft_putstr(params_dir->name);
		ft_putstr("\n");
		params_dir = params_dir->next;
	}
}
