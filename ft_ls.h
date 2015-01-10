/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/10 18:42:46 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define _FILE_OFFSET_BITS 64
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/includes/libft.h"

typedef struct				s_option
{
	int						l;
	int						r;
	int						recursive;
	int						a;
	int						t;
	int						attr;
	int						acl;
}							t_option;

typedef struct				s_content
{
	char					*name;
	char					*path;
	void					*val;
	unsigned long			mode;
	long					nlink;
	long					uid;
	long					gid;
	long					rdev;
	long long				size;
	long					mtime;
	long					blocks;
	struct s_content		*next;
}							t_cont;

typedef struct				s_param
{
	t_cont					*err;
	t_cont					*file;
	t_cont					*dir;
	int						err_counter;
	int						file_counter;
	int						dir_counter;
	char					*dir_name;
	int						dir_num;
	int						flag;
}							t_param;

typedef struct				s_biggest
{
	int						link_biggest;
	int						size_biggest;
	int						uid_biggest;
	int						gid_biggest;
	int						flag_there_is_dev;
	int						flag_big_file;
	int						flag_not_hidden;
	long					blocks;
}							t_biggest;

#endif
