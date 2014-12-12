/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:02:53 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/11 20:37:04 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_cont		*create_new_container(char *name, t_cont *new, struct stat *buf, t_option option)
{
	new = 0;
	if ((new = (t_cont *)malloc(sizeof(t_cont))) == 0)
		return (0);
	if (buf != 0)
	{
		new->mode = buf->st_mode;
		new->nlink = buf->st_nlink;
		new->uid = buf->st_uid;
		new->gid = buf->st_gid;
		new->rdev = buf->st_rdev;
		new->size = buf->st_size;
		new->mtime = buf->st_mtime;
	}
	new->name = ft_strdup(name);
	new->next = 0;
	if (option.t == 0 || buf == 0)
	{
		new->val = (char *)malloc(ft_strlen(name) + 1);
		ft_memcpy(new->val, name, ft_strlen(name) + 1);
	}
	else
	{	
		new->val = (time_t *)malloc(sizeof(new->mtime));
		//		new->val = new->mtime;
	}
	return (new);
}

int			detect_type(char *name, t_cont *new, t_option option)
{
	struct stat			*buf;
	int					i;

	i = stat(name, buf);
	if (i == -1)
	{
		new = create_new_container(name, new, 0, option);
		return (-1);
	}
	new = create_new_container(name, new, buf, option);
	if (S_ISREG(buf->st_mode))
		return (1);
	else if (S_ISDIR(buf->st_mode))
		return (2);
	return (0);
}

void		collect_params(char *path, t_option option)
{
	static t_cont		*params_err;
	static t_cont		*params_file;
	static t_cont		*params_dir;
	t_cont				*new;

	if (detect_type(path, new, option) == -1)
		add(&params_err, new, &ft_strcmp);
	else if (detect_type(path, new, option) == 1)
	{
		if (option.empty == 1)
			add(&params_file, new, &ft_strcmp);
		else if (option.t == 1 && option.r == 1)
			add(&params_file, new, &ft_numcmp_rev);
		else if (option.t == 1 && option.r == 0)
			add(&params_file, new, &ft_numcmp);
		else if (option.t == 0 && option.r == 1)
			add(&params_file, new, &ft_strcmp_rev);
	}
	else if (detect_type(path, new, option) == 2)
	{
		if (option.empty == 1)
			add(&params_dir, new, &ft_strcmp);
		else if (option.t == 1 && option.r == 1)
			add(&params_dir, new, &ft_numcmp_rev);
		else if (option.t == 1 && option.r == 0)
			add(&params_dir, new, &ft_numcmp);
		else if (option.t == 0 && option.r == 1)
			add(&params_dir, new, &ft_strcmp_rev);
	}
}

int					main(int ac, char **av)
{
	t_option		option;
	int				i;

	if (ac == 1)
	{
	  //		list_content_dir(".");
		return (0);
	}
	i = treat_options(&option, av);
	while (i != ac)
	{
		collect_params(av[i], option);
		i++;
	}
	return (0);
}
