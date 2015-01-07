/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:12:18 by avallete          #+#    #+#             */
/*   Updated: 2015/01/07 13:12:20 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			sort_by_size(t_llstat src, t_llstat new)
{
	if (src.size > new.size)
		return (1);
	else if (src.size < new.size)
		return (-1);
	else
		return (ft_strcmp(new.filename, src.filename));
}

int			sort_by_time(t_llstat src, t_llstat new)
{
	if (src.date > new.date)
		return (1);
	else if (src.date < new.date)
		return (-1);
	else
		return (ft_strcmp(new.filename, src.filename));
}

int			sort_by_alpha(t_llstat src, t_llstat new)
{
	if (ft_strcmp(new.filename, src.filename) > 0)
		return (1);
	else
		return (-1);
}
