/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:02:25 by bbarakov          #+#    #+#             */
/*   Updated: 2014/12/12 20:30:55 by bbarakov         ###   ########.fr       */
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

typedef struct				s_cont_params
{
	t_cont					*err;
	t_cont					*file;
	t_cont					*dir;
}							t_cont_params;

//extern t_option				option;

void						print(t_cont_params lst, t_option option);
int							list_content_dir(char *s);
void						handle_err(char *s);
int							treat_options(t_option *option, char **av);
int							add(t_cont **lst, t_cont *new, long (*f)(void *a, void *b));

#endif
