/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misclsl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:53:10 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 13:50:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			ft_oldtime(int32_t timefile)
{
	time_t currenttime;

	currenttime = 0;
	time(&currenttime);
	if ((timefile - currenttime) <= -15811200 || (currenttime - timefile) <= -1)
		return (1);
	return (0);
}

void			test_sizeinfos(t_llstat *statsfile, size_t *infos, char *choice)
{
	if (((!(choice[2])) && statsfile->filename[0] != '.') || (choice[2]))
	{
		if (ft_nbrlen(statsfile->nbhlink) > infos[0])
			infos[0] = ft_nbrlen(statsfile->nbhlink);
		if (statsfile->owner)
		{
			if (ft_strlen(statsfile->owner) > infos[1])
				infos[1] = ft_strlen(statsfile->owner);
		}
		if (statsfile->group)
		{
			if (ft_strlen(statsfile->group) > infos[2])
				infos[2] = ft_strlen(statsfile->group);
		}
		if (ft_nbrlen(statsfile->size) > infos[3])
			infos[3] = ft_nbrlen(statsfile->size);
		if (ft_oldtime(statsfile->date))
			infos[4] = 1;
		infos[5] += statsfile->stats.st_blocks;
		infos[6] = 1;
	}
}
