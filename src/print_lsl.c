/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:13:56 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 18:58:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_devices(dev_t dev)
{
	int				f;
	unsigned int	maj;
	unsigned int	min;
	char			*tmp;

	maj = MAJ(dev);
	min = MIN(dev);
	f = 4 - ft_nbrlen(maj);
	while (f-- > 1)
		ft_bufferize(1, " ", false);
	tmp = ft_itoa(maj);
	ft_bufferize(1, tmp, false);
	free(tmp);
	ft_bufferize(1, ",", false);
	f = 4 - ft_nbrlen(min);
	while (f-- > 1)
		ft_bufferize(1, " ", false);
	tmp = ft_itoa(min);
	ft_bufferize(1, tmp, false);
	free(tmp);
	ft_bufferize(1, " ", false);
}

void print_ls(t_llstat *stats, char *options)
{
	if (((!(options[2])) && (stats->filename[0] != '.')) || options[2] ||\
			((options[7]) && ft_strcmp(stats->filename, ".") &&\
			ft_strcmp(stats->filename, "..")))
	{
		ft_bufferize(1, stats->filename, false);
		ft_bufferize(1, "\n", false);
	}
}

void print_lsl_one(t_llstat *stats, size_t *infos, char *options)
{
	print_typefile(stats->filetype);
	print_rights(stats->accesright, stats);
	print_hlink(stats->nbhlink, infos[0]);
	if (options[0] != 2)
		print_owner(stats->owner, infos[1]);
	print_group(stats->group, infos[2]);
	if (stats->filetype != 2 && stats->filetype != 6)
		print_size(stats->size, infos[3]);
	else
		print_devices(stats->dev);
}

void print_lsl(t_llstat *stats, size_t *infos, char *options)
{
	if (((!(options[2])) && (stats->filename[0] != '.')) || options[2] ||\
			((options[7]) && ft_strcmp(stats->filename, ".") &&\
			ft_strcmp(stats->filename, "..")))
	{
		if (infos[6] > 0)
		{
			print_total(infos[5]);
			infos[6] = 0;
		}
		infos[5] = 0;
		print_lsl_one(stats, infos, options);
		print_time(stats->date, infos[4]);
		ft_bufferize(1, stats->filename, false);
		if (stats->filetype == 10)
			print_linkpath(stats->pathname, stats->size);
		ft_bufferize(1, "\n", false);
	}
}
