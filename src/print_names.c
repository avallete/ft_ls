/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:40:46 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 15:25:16 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void print_size(off_t size, size_t maxcol)
{
	size_t i;
	char *tmp;

	i = (maxcol - (ft_nbrlen(size) - 1));
	while (i--)
		ft_bufferize(1, " ", false);
	tmp = ft_itoa(size);
	ft_bufferize(1, tmp, false);
	free(tmp);
	ft_bufferize(1, " ", false);
}

void print_group(char *groupname, size_t maxcol)
{
	size_t i;

	i = (maxcol - ft_strlen(groupname)) + 1;
	ft_bufferize(1, groupname, false);
	while (i-- > 0)
		ft_bufferize(1, " ", false);
}

void print_owner(char *owner, size_t maxcol)
{
	size_t i;

	i = maxcol - ft_strlen(owner);
	ft_bufferize(1, owner, false);
	while (i-- > 0)
		ft_bufferize(1, " ", false);
	ft_bufferize(1, " ", false);
}

void print_hlink(int nb, size_t maxcol)
{
	size_t i;
	char *tmp;

	i = (maxcol - ft_nbrlen(nb));
	while (i--)
		ft_bufferize(1, " ", false);
	tmp = ft_itoa(nb);
	ft_bufferize(1, tmp, false);
	free(tmp);
	ft_bufferize(1, " ", false);
}
