/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/05 15:49:13 by bbarakov         ###   ########.fr       */
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
// # include <sys/acl.h>
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
  	int						flag_is_param;
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

void						content_dir(char *s, t_param *lst, t_option option);
void						collect_params(char *path, t_option option, t_param *lst);
int							fill_list(t_cont **lst, t_cont *new, t_option option);
int							detect_type(char *name, char *path, t_cont **new, t_option option);
int							sort(t_cont *list, t_cont *new, t_option o, long (*f)(void *a, void *b));
int							sort_pm(t_cont *list, t_cont *new, long (*f)(void *a, void *b));
void						print_dir_content(char *path, t_cont *list, t_param *lst, t_option option);
void						print(t_param *lst, t_option option);
void						handle_err_eacces(char *s1, char *s2);
void						handle_err(char *s1, char *s2);
int							treat_options(t_option *option, char **av);
int							add(t_cont **lst, t_cont *new, t_option opt, long (*f)(void *a, void *b));
void						put_attr(t_cont *list, t_biggest *bist, t_option option);
void						file_type(unsigned long mode);
void						file_perm_user(unsigned long mode);
void						file_perm_group(unsigned long mode);
void						file_perm_others(unsigned long mode);
void						file_links(long link, t_biggest *bist, int xattr, int acl);
void						file_user(long user, t_biggest *bist);
void						file_group(long group, t_biggest *bist);
void						file_size(long long size, t_biggest *bist);
void						file_time(long mtime);
void						file_devices(long rdev);
int 						file_xattr(char *path);
int							file_acl(char *path);
int							put_xattr_value(char *list, char *path);
void						put_xattr(char *path, int list_len);
int							put_acl(char *path);
t_biggest					*get_biggest(t_cont *list, t_option option, int flag_i_am_dir);
t_biggest					*get_biggest_attr(t_cont *list, t_option option, t_biggest *bist, int flag_i_am_dir);
void						free_param(t_param *lst, t_option option);
void						free_cont(t_cont *list, t_option option);
void						free_cont_err(t_cont *list);

#endif
