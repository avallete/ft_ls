/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:12:59 by avallete          #+#    #+#             */
/*   Updated: 2015/01/07 13:13:01 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		take_name(t_llstat *statsfile, char *pathname, char *filename)
{
	statsfile->filename = ft_strdup(filename);
	statsfile->pathname = ft_strjoin(pathname, filename);
}

void		take_stats(t_llstat *statsfile, size_t *keep_infos, \
		char *choice, t_ltree **tree)
{
	init_lstat(statsfile, choice);
	test_cols(*statsfile, keep_infos, tree, choice);
}

void		test_cols(t_llstat statsfile, size_t *keep_infos, \
		t_ltree **tree, char *choice)
{
	test_sizeinfos(&statsfile, keep_infos, choice);
	check_dev(keep_infos, statsfile);
	if (!(choice[10]))
		choice[1] ? ltree_insert_data(tree, statsfile, &sort_by_time) :\
			ltree_insert_data(tree, statsfile, &sort_by_alpha);
	else
		ltree_insert_data(tree, statsfile, &sort_by_size);
}

void		check_dev(size_t *keep_infos, t_llstat statsfile)
{
	if (statsfile.filetype == 2 || statsfile.filetype == 6)
		keep_infos[3] = 8;
}
