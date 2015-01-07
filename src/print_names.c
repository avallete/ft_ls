/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:40:46 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 11:38:39 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_size(off_t size, size_t maxcol)
{
	size_t i;

	i = (maxcol - (ft_nbrlen(size) - 1));
	while (i--)
		ft_putchar(' ');
	ft_putnbr(size);
	ft_putchar(' ');
}

void print_group(char *groupname, size_t maxcol)
{
	size_t i;

	i = (maxcol - ft_strlen(groupname)) + 1;
	ft_putstr(groupname);
	while (i--)
		ft_putchar(' ');
}

void print_owner(char *owner, size_t maxcol)
{
	size_t i;

	i = maxcol - ft_strlen(owner);
	ft_putstr(owner);
	while (i--)
		ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar(' ');
}

void print_hlink(int nb, size_t maxcol)
{
	size_t i;

	i = (maxcol - ft_nbrlen(nb));
	while (i--)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putchar(' ');
}
