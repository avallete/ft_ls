/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:41:11 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 15:23:59 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_groupmod(int st_mode)
{
	st_mode & S_IRGRP ? ft_bufferize(1, "r", false) : ft_bufferize(1, "-", false);
	st_mode & S_IWGRP ? ft_bufferize(1, "w", false) : ft_bufferize(1, "-", false);
	if (st_mode & S_IXGRP)
	{
		if (st_mode & S_ISGID)
			ft_bufferize(1, "s", false);
		else
			ft_bufferize(1, "x", false);
	}
	else if (!(st_mode & S_IXGRP))
	{
		if (st_mode & S_ISGID)
			ft_bufferize(1, "S", false);
		else
			ft_bufferize(1, "-", false);
	}
}

void print_othermod(int st_mode)
{
	st_mode & S_IROTH ? ft_bufferize(1, "r", false) : ft_bufferize(1, "-", false);
	st_mode & S_IWOTH ? ft_bufferize(1, "w", false) : ft_bufferize(1, "-", false);
	if (st_mode & S_ISVTX)
	{
		if ((!(st_mode & S_IROTH)) && (!(st_mode & S_IXOTH)))
			ft_bufferize(1, "T", false);
		if (((st_mode & S_IROTH)) && ((st_mode & S_IXOTH)))
			ft_bufferize(1, "t", false);
	}
	else
		st_mode & S_IXOTH ? ft_bufferize(1, "x", false) : ft_bufferize(1, "-", false);
}

void print_extended(t_llstat *stats)
{
	char attr[256];

	ft_bzero(attr, 256);
	listxattr(stats->pathname, attr, 255);
	if (ft_strlen(attr) > 0)
		ft_bufferize(1, "@ ", false);
	else if (acl_extended_file(stats->pathname) > 0)
		ft_bufferize(1, "+ ", false);
}

void print_usrmod(int st_mode)
{
	st_mode & S_IRUSR ? ft_bufferize(1, "r", false) : ft_bufferize(1, "-", false);
	st_mode & S_IWUSR ? ft_bufferize(1, "w", false) : ft_bufferize(1, "-", false);
	if (st_mode & S_IXUSR)
	{
		if (st_mode & S_ISUID)
			ft_bufferize(1, "s", false);
		else
			ft_bufferize(1, "x", false);
	}
	else if (!(st_mode & S_IXUSR))
	{
		if (st_mode & S_ISUID)
			ft_bufferize(1, "S", false);
		else
			ft_bufferize(1, "-", false);
	}
}

void print_rights(int st_mode, t_llstat *stats)
{
	print_usrmod(st_mode);
	print_groupmod(st_mode);
	print_othermod(st_mode);
	print_extended(stats);
	ft_bufferize(1, " ", false);
}
