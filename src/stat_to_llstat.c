/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_to_llstat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 11:01:08 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 12:27:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned char take_typefile(mode_t c)
{
	if (S_ISREG(c))
		return (0);
	if (S_ISDIR(c))
		return (4);
	if (S_ISLNK(c))
		return (10);
	if (S_ISBLK(c))
		return (6);
	if (S_ISFIFO(c))
		return (1);
	if (S_ISSOCK(c))
		return (12);
	if (S_ISCHR(c))
		return (2);
	return (14);
}
