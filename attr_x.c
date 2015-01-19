/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:15:49 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/13 12:12:33 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_ls_prototypes.h"

int					file_acl(char *path)
{
	acl_t			acl;

	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != 0)
	{
		acl_free((void *)acl);
		return (1);
	}
	return (0);
}

int					put_xattr_value(char *list, char *path)
{
	int				val_len;
	int				i;
	char			*value;

	value = 0;
	if ((val_len = getxattr(path, list, value, 0, 0, XATTR_NOFOLLOW)) == -1)
		return (-1);
	i = 7 - ft_getsize_nbr(val_len);
	while (i > 0)
	{
		ft_putstr(" ");
		i--;
	}
	ft_putnbr(val_len);
	return (val_len);
}

void				put_xattr(char *path, int list_len, t_option *option)
{
	int				i;
	int				len;
	char			*list;

	len = list_len;
	list = 0;
	if ((list = (char *)malloc(list_len + 1)) == 0)
		handle_err_eacces("ft_ls: ", "malloc", option);
	listxattr(path, list, list_len, XATTR_NOFOLLOW);
	while (list_len > 0)
	{
		ft_putstr("\t");
		ft_putstr(list);
		i = ft_strlen(list) + 1;
		list += i;
		list_len -= i;
		ft_putstr("\t");
		put_xattr_value(list - i, path);
		ft_putstr("\n");
	}
	list = list - len;
	free(list);
}

int					file_xattr(char *path)
{
	int				list_len;
	char			*list;

	list = 0;
	if ((list_len = listxattr(path, list, 0, XATTR_NOFOLLOW)) == -1)
		return (-1);
	return (list_len);
}
