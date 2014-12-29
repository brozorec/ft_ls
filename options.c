/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:02:53 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/29 14:28:48 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					illigal_option(char *s)
{
	int		i;
	char	ch;

	i = 1;
	while (s[i])
	{
		if (s[i] != 'l' && s[i] != 'r' && s[i] != 'R' &&
			s[i] != 'a' && s[i] != 't')
		{
			ch = s[i];
			handle_err("ft_ls: illegal option -- ");
			handle_err(ft_strjoin(&ch, "\n"));
			handle_err(ft_strjoin("usage: ft_ls [-Ralrt] [file ...]", "\n"));
			exit (2);
		}
		i++;
	}
	return (0);
}

t_option			set_options(t_option option, char *s)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if (ft_strchr(s, 'l'))
			option.l = 1;
		if (ft_strchr(s, 'r'))
			option.r = 1;
		if (ft_strchr(s, 'R'))
			option.recursive = 1;
		if (ft_strchr(s, 'a'))
			option.a = 1;
		if (ft_strchr(s, 't'))
			option.t = 1;
		i++;
	}
	return (option);
}

t_option			init_option(t_option option)
{
	option.empty = 0;
	option.emp_tr = 0;
	option.l = 0;
	option.r = 0;
	option.recursive = 0;
	option.a = 0;
	option.t = 0;
	return (option);
}

int					treat_options(t_option *option, char **av)
{
	int		i;

	i = 1;
	*option = init_option(*option);
	while (av[i] && av[i][0] == '-')
	{
		if (ft_strlen(av[i]) == 1)
		{
			i--;
			break ;
		}
		if (ft_strlen(av[i]) == 2 && av[i][1] == '-')
		{
			i++;
			break ;
		}
		if (illigal_option(av[i]) == 0)
			*option = set_options(*option, av[i]);
		i++;
	}
	if (option->l == 0 && option->r == 0 && option->recursive == 0 &&
		option->a == 0 && option->t == 0)
		option->empty = 1;
	if (option->t == 0 && option->r == 0)
		option->emp_tr = 1;
	return (i);
}
