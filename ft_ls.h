/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/14 18:08:38 by bbarakov         ###   ########.fr       */
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
	long long				mtime;
	struct s_content		*next;
}							t_cont;

typedef struct				s_param
{
	t_cont					*err;
	t_cont					*file;
	t_cont					*dir;
	int						dir_num;
}							t_param;


int							content_dir(char *s, t_param lst, t_option option);
void						collect_params(char *path, t_option option, t_param *lst);
int							fill_list(t_cont **lst, t_cont *new, t_option option);
int							detect_type(char *name, char *path, t_cont **new, t_option option);
void						print_dir_content(char *path, t_cont *list, t_param lst, t_option option);
void						print(t_param lst, t_option option);
void						handle_err(char *s);
int							treat_options(t_option *option, char **av);
int							add(t_cont **lst, t_cont *new, long (*f)(void *a, void *b));
void						get_attr(t_cont *list);

#endif
