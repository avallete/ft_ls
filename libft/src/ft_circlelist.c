/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circlelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 20:29:06 by avallete          #+#    #+#             */
/*   Updated: 2015/05/29 20:31:25 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_circlelist(t_dlst **list)
{
    t_dlst *begin;
    t_dlst *end;

    begin = *list;
    end = *list;
    if (begin)
    {
        while (end->next)
            end = end->next;
        end->next = begin;
    }
}