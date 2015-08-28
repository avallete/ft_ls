/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:14:06 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 14:07:23 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

time_t		take_time(char *choice, t_llstat *statstree)
{
	if (choice[8] && (!choice[9]))
	{
		if (choice[8] == 1)
			return (statstree->stats.st_atim.tv_sec);
		return (statstree->stats.st_ctim.tv_sec);
	}
	return (statstree->stats.st_mtim.tv_sec);
}

int			init_lstat(t_llstat *statstree, char *choice)
{
	char *tmp = NULL;
	statstree->owner[0] = 0;
	statstree->group[0] = 0;
	statstree->filetype = take_typefile(statstree->stats.st_mode);
	statstree->accesright = statstree->stats.st_mode;
	statstree->nbhlink = statstree->stats.st_nlink;
	statstree->dev = statstree->stats.st_rdev;
	if (!(getpwuid(statstree->stats.st_uid)))
	{
		tmp = ft_itoa(statstree->stats.st_uid);
		ft_strcpy(statstree->owner, tmp);
		free(tmp);
	}
	else
		ft_strcpy(statstree->owner, getpwuid(statstree->stats.st_uid)->pw_name);
	if (!(getgrgid(statstree->stats.st_gid)))
	{
		tmp = ft_itoa(statstree->stats.st_gid);
		ft_strcpy(statstree->group, tmp);
		free(tmp);
	}
	else
		ft_strcpy(statstree->group, getgrgid(statstree->stats.st_gid)->gr_name);
	statstree->size = statstree->stats.st_size;
	statstree->date = take_time(choice, statstree);
	return (0);
}

t_ltree		*create_node_stat(t_llstat datas)
{
	t_ltree *new;

	new = (t_ltree*)malloc(sizeof(t_ltree));
	new->left = NULL;
	new->right = NULL;
	new->infos = (datas);
	return (new);
}
