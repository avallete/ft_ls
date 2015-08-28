/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 12:16:21 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 20:16:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ls_file(t_ltree **tree, char *pathname, \
		char *choice, size_t *keep_infos)
{
	t_llstat		statsfile;

	ft_strcpy(statsfile.filename, pathname);
	ft_strcpy(statsfile.pathname, pathname);
	if (((lstat(statsfile.pathname, &statsfile.stats))) != -1)
	{
		init_lstat(&statsfile, choice);
		test_cols(statsfile, keep_infos, tree, choice);
		keep_infos[6] = 0;
	}
	else
		print_error(statsfile.pathname);
}

size_t		*ls_read_stat(t_ltree **tree, char *pathname, char *choice)
{
	struct dirent	*file;
	DIR				*rep;
	t_llstat		statsfile;
	static size_t	keep_infos[7] = {0};

	if ((rep = opendir(pathname)))
	{
		if (!(check_slash(pathname)))
			ft_strcat(pathname, "/");
		while ((file = readdir(rep)))
		{
			statsfile.pathname[0] = 0;
			statsfile.filename[0] = 0;
			take_name(&statsfile, pathname, file->d_name);
			if (((lstat(statsfile.pathname, &statsfile.stats))) != -1)
				take_stats(&statsfile, keep_infos, choice, tree);
			else
				print_error(statsfile.filename);
		}
		closedir(rep);
	}
	else if (errno == ENOENT || errno == ENOTDIR)
		ls_file(tree, pathname, choice, keep_infos);
	else
		print_error(filename(pathname));
	return (keep_infos);
}
