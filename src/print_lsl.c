/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:13:56 by avallete          #+#    #+#             */
/*   Updated: 2015/08/27 23:51:11 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_devices(dev_t dev)
{
	int				i;
	int				f;
	unsigned int	maj;
	unsigned int	min;
	char			buf[10];

	i = 0;
	maj = MAJ(dev);
	min = MIN(dev);
	ft_bzero(buf, 10);
	f = 4 - ft_nbrlen(maj);
	while (i++ < f)
		buf[i] = ' ';
	ft_putstr(buf);
	ft_putnbr(maj);
	i = 0;
	ft_putstr(",");
	f = 4 - ft_nbrlen(min);
	while (i++ < f)
		buf[i] = ' ';
	ft_putstr(buf);
	ft_putnbr(min);
	ft_putchar(' ');
}

void print_ls(t_llstat *stats, char *options)
{
	if (((!(options[2])) && (stats->filename[0] != '.')) || options[2] ||\
			((options[7]) && ft_strcmp(stats->filename, ".") &&\
			ft_strcmp(stats->filename, "..")))
		ft_putendl(stats->filename);
}

void print_lsl_one(t_llstat *stats, size_t *infos, char *options)
{
	print_typefile(stats->filetype);
	print_rights(stats->accesright, stats);
	print_hlink(stats->nbhlink, infos[0]);
	if (stats->owner && options[0] != 2)
		print_owner(stats->owner, infos[1]);
	if (stats->group)
		print_group(stats->group, infos[2]);
	if (stats->filetype != 2 && stats->filetype != 6)
		print_size(stats->size, infos[3]);
	else
		print_devices(stats->dev);
	if (stats->owner)
		free(stats->owner);
	if (stats->group)
		free(stats->group);
	stats->owner = NULL;
	stats->group = NULL;
}

void print_lsl(t_llstat *stats, size_t *infos, char *options)
{
	if (((!(options[2])) && (stats->filename[0] != '.')) || options[2] ||\
			((options[7]) && ft_strcmp(stats->filename, ".") &&\
			ft_strcmp(stats->filename, "..")))
	{
		if (infos[6])
		{
			print_total(infos[5]);
			infos[6] = 0;
		}
		infos[5] = 0;
		print_lsl_one(stats, infos, options);
		print_time(stats->date, infos[4]);
		ft_putstr(stats->filename);
		if (stats->filetype == 10)
			print_linkpath(stats->pathname, stats->size);
		ft_putchar('\n');
		if (stats->filename)
		{
			if (stats->filetype != 4)
			{
				free(stats->filename);
				stats->filename = NULL;
			}
		}
	}
}
