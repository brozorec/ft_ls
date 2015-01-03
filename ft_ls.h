/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/03 15:18:30 by bbarakov         ###   ########.fr       */
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
	char					*dir_name;
	int						dir_num;
	int						counter;
	int						flag;
}							t_param;

typedef struct 				s_biggest
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

t_cont						*content_dir(char *s, t_param *lst, t_option option);
void						collect_params(char *path, t_option option, t_param *lst);
int							fill_list(t_cont **lst, t_cont *new, t_option option);
int							detect_type(char *name, char *path, t_cont **new, t_option option);
void						print_dir_content(char *path, t_cont *list, t_param *lst, t_option option);
void						print(t_param *lst, t_option option);
void						handle_err_eacces(char *s1, char *s2);
void						handle_err(char *s1, char *s2);
int							treat_options(t_option *option, char **av);
int							add(t_cont **lst, t_cont *new, t_option opt, long (*f)(void *a, void *b));
void						put_attr(t_cont *list, t_biggest *bist, t_option option);
void						file_type(unsigned long mode);
void						file_perm_first(unsigned long mode);
void						file_perm_second(unsigned long mode);
void						file_links(long link, t_biggest *bist);
void						file_user(long user, t_biggest *bist);
void						file_group(long group, t_biggest *bist);
void						file_size(long long size, t_biggest *bist);
void						file_time(long mtime);
void						file_devices(long rdev);
t_biggest					*get_biggest(t_cont *list, t_option option, int flag_i_am_dir);
t_biggest					*get_biggest_attr(t_cont *list, t_option option, t_biggest *bist, int flag_i_am_dir);
void						free_param(t_param *lst, t_option option);
void						free_cont(t_cont *list, t_option option);
void						free_cont_err(t_cont *list);

#endif
