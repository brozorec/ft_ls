/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:17:08 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/10 18:41:54 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_prototypes.h"

void
	collect_params(char *name, t_option option, t_param *lst)
{
	t_cont				*new;
	int					i;

	new = 0;
	i = detect_type(name, name, &new, option);
	new->path = ft_strdup(name);
	if (i == 0)
	{
		add(&(lst->err), new, option, &ft_strcmp);
		lst->err_counter++;
	}
	else if (i == 1)
	{
		fill_list(&(lst->file), new, option);
		lst->file_counter++;
	}
	else if (i == 2)
	{
		fill_list(&(lst->dir), new, option);
		lst->dir_num++;
		lst->dir_counter++;
	}
}

t_param
	*cont_params_init(void)
{
	t_param			*new;

	if ((new = (t_param *)malloc(sizeof(*new))) == 0)
		handle_err_eacces("ft_ls: ", "malloc");
	new->err = 0;
	new->file = 0;
	new->dir = 0;
	new->dir_name = 0;
	new->dir_num = 0;
	new->dir_counter = 0;
	new->err_counter = 0;
	new->file_counter = 0;
	new->flag = 0;
	return (new);
}

int
	main(int ac, char **av)
{
	int				i;
	t_param			*lst;
	t_option		option;

	i = treat_options(&option, av);
	lst = cont_params_init();
	if (ac == 1 || (ac == i))
		collect_params(".", option, lst);
	while (i != ac)
	{
		collect_params(av[i], option, lst);
		i++;
	}
	print(lst, option);
	return (0);
}
