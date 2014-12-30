/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:17:08 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/30 20:16:35 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param
	*cont_params_init(void)
{
	t_param			*new;

	if ((new = (t_param *)malloc(sizeof(new))) == 0)
		return (0);
	if ((new->err = (t_cont *)malloc(sizeof(new->err))) == 0)
		return (0);
	if ((new->file = (t_cont *)malloc(sizeof(new->file))) == 0)
		return (0);
	if ((new->dir = (t_cont *)malloc(sizeof(new->dir))) == 0)
		return (0);
	new->err = 0;
	new->file = 0;
	new->dir = 0;
	new->dir_name = 0;
	new->dir_num = 0;
	new->counter = 0;
	new->flag = 0;
	return (new);
}

void
	free_param(t_param *lst)
{
	free_cont(lst->err);
	free_cont(lst->file);
	free_cont(lst->dir);
	free(lst);
}

int
	main(int ac, char **av)
{
	int				i;
	t_param			*lst;
	t_option		option;

	i = treat_options(&option, av);
	lst = cont_params_init();
	if (ac == 1 || (ac == 2 && i == 2))
		collect_params(".", option, lst);
	while (i != ac)
	{
		collect_params(av[i], option, lst);
		i++;
	}
	print(lst, option);
	free_param(lst);
	return (0);
}
