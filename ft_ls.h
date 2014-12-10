/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/10 19:31:45 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

typedef struct				s_option
{
	int						empty;
	int						l;
	int						r;
	int						recursive;
	int						a;
	int						t;
}							t_option;

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/includes/libft.h"

int							list_content_dir(char *s);
void						handle_err(char *s);

#endif
