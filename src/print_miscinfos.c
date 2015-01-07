/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_miscinfos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:40:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 12:40:36 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_linkpath(char *filename, off_t size)
{
	char *linkpath;

	size = 1000;
	linkpath = NULL;
	ft_putstr(" -> ");
	linkpath = (char*)malloc(sizeof(char) * size + 1);
	ft_bzero(linkpath, (sizeof(char) * size + 1));
	readlink(filename, linkpath, size);
	ft_putstr(linkpath);
	free(linkpath);
	linkpath = NULL;
}

void print_total(int st_blksize)
{
	ft_putstr("total ");
	ft_putnbr(st_blksize);
	ft_putchar('\n');
}

void print_time(time_t timefile, size_t oldtime)
{
	if (!oldtime)
		ft_putnstr((ctime(&timefile)) + 4, 12);
	else
	{
		if (ft_oldtime(timefile))
		{
			ft_putnstr((ctime(&timefile)) + 4, 6);
			ft_putchar(' ');
			ft_putnstr((ctime(&timefile)) + 19, 5);
		}
		else
			ft_putnstr((ctime(&timefile)) + 4, 12);
	}
	ft_putchar(' ');
}

void print_typefile(unsigned char type)
{
	if (type == 0 || type == 14 || type == 8)
		ft_putchar('-');
	if (type == 1)
		ft_putchar('p');
	if (type == 2)
		ft_putchar('c');
	if (type == 4)
		ft_putchar('d');
	if (type == 6)
		ft_putchar('b');
	if (type == 10)
		ft_putchar('l');
	if (type == 12)
		ft_putchar('s');
}
