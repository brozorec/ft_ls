/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prototypes.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:36:58 by bbarakov          #+#    #+#             */
/*   Updated: 2015/01/12 13:31:46 by bbarakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_PROTOTYPES_H
# define FT_LS_PROTOTYPES_H

# include "./ft_ls.h"

void		content_dir(char *s, t_param *lst, t_cont *dir, t_option *option);
void		collect_params(char *path, t_option *option, t_param *lst);
int			fill_list(t_cont **lst, t_cont *new, t_option option);
int			detect_type(char *name, char *path, t_cont **new, t_option *option);
int			sort(t_cont *l, t_cont *n, t_option o, long (*f)(void *a, void *b));
void		print_dir_content(char *path, t_cont *l, t_param *lst, t_option *o);
void		print(t_param *lst, t_option *option);
void		handle_err_eacces(char *s1, char *s2, t_option *option);
void		handle_err(char *s1, char *s2, t_option *option);
int			treat_options(t_option *option, char **av);
int			add(t_cont **l, t_cont *n, t_option o, long (*f)(void *a, void *b));
void		put_attr(t_cont *list, t_param *lst, t_biggest *bist, t_option *o);
void		file_type(unsigned long mode);
void		file_perm_user(unsigned long mode);
void		file_perm_group(unsigned long mode);
void		file_perm_others(unsigned long mode);
void		file_links(long link, t_biggest *bist, int xattr, int acl);
void		file_user(long user, t_biggest *bist);
void		file_group(long group, t_biggest *bist);
void		file_size(long long size, t_biggest *bist);
void		file_time(long mtime);
void		file_devices(long rdev);
int			file_xattr(char *path);
int			file_acl(char *path);
int			put_xattr_value(char *list, char *path);
void		put_xattr(char *path, int list_len, t_option *option);
t_biggest	*get_biggest(t_cont *list, t_option *option, int flag_i_am_dir);
t_biggest	*get_biggest_attr(t_cont *list, t_option o, t_biggest *b, int flag);
void		free_param(t_param *lst, t_option option);
void		free_cont(t_cont *list, t_option option);
void		free_cont_err(t_cont *list);

#endif
