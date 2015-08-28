/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_miscinfos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:40:29 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 19:21:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_linkpath(char *filename, off_t size)
{
	char *linkpath;

	size = 1000;
	linkpath = NULL;
	ft_bufferize(1, " -> ", false);
	linkpath = (char*)malloc(sizeof(char) * size + 1);
	ft_bzero(linkpath, (sizeof(char) * size + 1));
	readlink(filename, linkpath, size);
	ft_bufferize(1, linkpath, false);
	free(linkpath);
	linkpath = NULL;
}

void print_total(int st_blksize)
{
	char *tmp;
	ft_bufferize(1, "total ", false);
	tmp = ft_itoa(st_blksize);
	ft_bufferize(1, tmp, false);
	free(tmp);
	ft_bufferize(1, "\n", false);
}

void print_time(time_t timefile, size_t oldtime)
{
	char* tmp;

	tmp = ctime(&timefile) + 4;
	tmp[12] = 0;
	if (!oldtime)
		ft_bufferize(1, tmp, false);
	else
	{
		if (ft_oldtime(timefile))
		{
			tmp[6] = 0;
			tmp[20] = 0;
			ft_bufferize(1, tmp, false);
			ft_bufferize(1, tmp + 15, false);
		}
		else
			ft_bufferize(1, tmp, false);
	}
	ft_bufferize(1, " ", false);
}

void print_typefile(unsigned char type)
{
	if (type == 0 || type == 14 || type == 8)
		ft_bufferize(1, "-", false);
	if (type == 1)
		ft_bufferize(1, "p", false);
	if (type == 2)
		ft_bufferize(1, "c", false);
	if (type == 4)
		ft_bufferize(1, "d", false);
	if (type == 6)
		ft_bufferize(1, "b", false);
	if (type == 10)
		ft_bufferize(1, "l", false);
	if (type == 12)
		ft_bufferize(1, "s", false);
}
