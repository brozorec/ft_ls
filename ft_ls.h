/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/16 18:43:14 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
//# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/includes/libft.h"

typedef struct				s_option
{
	int						empty;
	int						emp_tr;
	int						l;
	int						r;
	int						recursive;
	int						a;
	int						t;
}							t_option;

typedef struct				s_content
{
	char					*name;
	char					*path;
	char					*addr;
	void					*val;
	unsigned long			mode;
	long					nlink;
	long					uid;
	long					gid;
	long					rdev;
	long long				size;
	long long				mtime;
	struct s_content		*next;
}							t_cont;

typedef struct				s_param
{
	t_cont					*err;
	t_cont					*file;
	t_cont					*dir;
	char					*dir_name;
	int						dir_num;
	int						counter;
	int						flag;
}							t_param;

t_cont						*content_dir(char *s, t_param *lst, t_option option);
void						collect_params(char *path, t_option option, t_param *lst);
int							fill_list(t_cont **lst, t_cont *new, t_option option);
int							detect_type(char *name, char *path, t_cont **new, t_option option);
void						print_dir_content(char *path, t_cont *list, t_param *lst, t_option option);
void						print(t_param *lst, t_option option);
void						handle_err(char *s);
int							treat_options(t_option *option, char **av);
int							add(t_cont **lst, t_cont *new, long (*f)(void *a, void *b));
void						get_attr(t_cont *list, t_option option);
void						file_type(unsigned long mode);
void						file_perm_first(unsigned long mode);
void						file_type_second(unsigned long mode);
void						file_links(long link, int biggest);
void						file_user_group(long user, long group);
void						file_size(long long size, int biggest);
int							get_biggest_link(t_cont *copy);
int							get_biggest_size(t_cont *copy);
int							get_biggest_gid(t_cont *copy);
int							get_biggest_uid(t_cont *copy);

#endif
