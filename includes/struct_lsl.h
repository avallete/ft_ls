/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_lsl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:18:25 by avallete          #+#    #+#             */
/*   Updated: 2015/01/07 13:18:27 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LSL_H
# define STRUCT_LSL_H

/*
**Macros st_rdev--------------------
*/

# define MINORBITS				24
# define MINORMASK				((1U << MINORBITS) - 1)
# define MAJ(dev)				((dev) >> MINORBITS)
# define MIN(dev)				((dev) & MINORMASK)
# define FIRST(rev, tree)		((rev > 0 ? tree->right : tree->left))
# define LAST(rev, tree)		((rev > 0 ? tree->left : tree->right))

typedef struct					s_llstat
{
	struct stat					stats;
	char						filetype;
	mode_t						accesright;
	int							nbhlink;
	char						*owner;
	char						*group;
	off_t						size;
	time_t						date;
	char						*filename;
	char						*pathname;
	dev_t						dev;
}								t_llstat;

typedef struct					s_ltree
{
	struct s_ltree				*right;
	struct s_ltree				*left;
	t_llstat					infos;
}								t_ltree;

/*
** ----------
** Misc.c
** ----------
*/
void							print_error(char *filename);
void							ft_putsterr(char *str);
void							ft_putsterr(char *str);
void							arg_is_dir(t_ltree *args, int *dir, int *file);
void							initialize_infos(size_t *infos);
char							*filename(char *pathname);
void							ft_putcerr(char c);

/*
** ----------
** ft_arguments.c
** ----------
*/
int								verify_argv(int argc, char **argv);
int								ft_arg(char *c, char e);
void							argument_sort(char **argv, int *tab, \
																char *choice);
void							print_files_args(t_ltree *args, \
												size_t *infos, char *options);
int								ft_arguments(int argc, char **argv, \
																char *choice);
int								check_slash(char *str);
void							print_dir_args(t_ltree *args, char *options);
int								test_linkdest(t_llstat infos);

/*
** ----------
** Set_up
** ----------
*/
void							set_up(char *argv, char	*choice);
void							call_setup(t_ltree *args, char *choice);
void							set_up_argv(int argc, char **argv, int i, \
																char *choice);
void							args_one(char *choice, char *pathname);

/*
** ----------
** Create Node
** ----------
*/
t_ltree							*create_node_stat(t_llstat datas);
int								init_lstat(t_llstat *statstree, char *choice);

/*
** ----------
** Misc for ls -l
** ----------
*/
void							test_sizeinfos(t_llstat *statsfile, size_t \
														*infos, char *choice);
char							ft_oldtime(int32_t timefile);

/*
** ----------
** Binary Tree
** ----------
*/
void							ltree_insert_data(t_ltree **tree, \
								t_llstat data, int (*f)(t_llstat, t_llstat));

/*
** ----------
** Sort type
** ----------
*/
int								sort_by_time(t_llstat src, t_llstat new);
int								sort_by_alpha(t_llstat src, t_llstat new);
int								sort_by_size(t_llstat src, t_llstat new);

/*
** ----------
** Grep stat infos to llstat
** ----------
*/
unsigned char					take_typefile(mode_t c);

/*
** ----------
** Read
** ----------
*/

size_t							*ls_read_stat(t_ltree **tree, char *pathname, \
																char *choice);
void							ls_file(t_ltree **tree, char *pathname, char \
												*choice, size_t *keep_infos);
/*
** ----------
** Take_stats
** ----------
*/
void							test_cols(t_llstat statsfile, size_t \
								*keep_infos, t_ltree **tree, char *choice);
void							check_dev(size_t *keep_infos, \
															t_llstat statsfile);
void							take_stats(t_llstat *statsfile, size_t \
								*keep_infos, char *choice, t_ltree **tree);
void							test_cols(t_llstat statsfile, size_t \
								*keep_infos, t_ltree **tree, char *choice);
void							take_name(t_llstat *statsfile, char \
								*pathname, char *filename);

/*
** ----------
** Print
** ----------
*/
void							print_dir(char *name, char *choice);
void							print_ls(t_llstat *stats, char *options);
void							ltree_print(t_ltree *root, size_t *infos, \
																char *options);
void							print_lsl_one(t_llstat *stats, size_t *infos, \
																char *options);
void							print_total(int st_blksize);
void							print_typefile(unsigned char type);
void							print_usrmod(int st_mode);
void							print_groupmod(int st_mode);
void							print_othermod(int st_mode);
void							print_rights(int st_mode, t_llstat *stats);
void							print_extended(t_llstat *stats);
void							print_hlink(int nb, size_t maxcol);
void							print_owner(char *owner, size_t maxcol);
void							print_group(char *groupname, size_t maxcol);
void							print_size(off_t size, size_t maxcol);
void							print_time(time_t timefile, size_t oldtime);
void							print_linkpath(char *filename, off_t size);
void							print_lsl(t_llstat *stats, size_t *infos, \
																char *options);
#endif
