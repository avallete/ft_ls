/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:41:11 by avallete          #+#    #+#             */
/*   Updated: 2015/08/27 14:57:38 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_groupmod(int st_mode)
{
	st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_IXGRP)
	{
		if (st_mode & S_ISGID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (!(st_mode & S_IXGRP))
	{
		if (st_mode & S_ISGID)
			ft_putchar('S');
		else
			ft_putchar('-');
	}
}

void print_othermod(int st_mode)
{
	st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_ISVTX)
	{
		if ((!(st_mode & S_IROTH)) && (!(st_mode & S_IXOTH)))
			ft_putchar('T');
		if (((st_mode & S_IROTH)) && ((st_mode & S_IXOTH)))
			ft_putchar('t');
	}
	else
		st_mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}

void print_extended(t_llstat *stats)
{
	char attr[256];

	ft_bzero(attr, 256);
	listxattr(stats->pathname, attr, 255);
	if (ft_strlen(attr) > 0)
		ft_putchar('@');
	else if (acl_extended_file(stats->pathname) > 0)
		ft_putchar('+');
	else
		ft_putchar(' ');
}

void print_usrmod(int st_mode)
{
	st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	if (st_mode & S_IXUSR)
	{
		if (st_mode & S_ISUID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (!(st_mode & S_IXUSR))
	{
		if (st_mode & S_ISUID)
			ft_putchar('S');
		else
			ft_putchar('-');
	}
}

void print_rights(int st_mode, t_llstat *stats)
{
	print_usrmod(st_mode);
	print_groupmod(st_mode);
	print_othermod(st_mode);
	print_extended(stats);
	ft_putchar(' ');
}
