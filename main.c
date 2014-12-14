/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:17:08 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/14 16:22:46 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param
	*cont_params_init(t_param *new)
{
	if (new->dir)
		new->dir = 0;
	if ((new = (t_param *)malloc(sizeof(new))) == 0)
		return (0);
	if ((new->err = (t_cont *)malloc(sizeof(new->err))) == 0)
		return (0);
	if ((new->file = (t_cont *)malloc(sizeof(new->file))) == 0)
		return (0);
	if ((new->dir = (t_cont *)malloc(sizeof(new->dir))) == 0)
		return (0);
	new->dir_num = 0;
	return (new);
}

int
	main(int ac, char **av)
{
	int				i;
	t_param			lst;
	t_option		option;

	i = treat_options(&option, av);
	cont_params_init(&lst);
	if (ac == 1 || (ac == 2 && i == 2))
	{
		content_dir(".", lst, option);
		return (0);
	}
	while (i != ac)
	{
		collect_params(av[i], option, &lst);
		i++;
	}
	print(lst, option);
	return (0);
}
