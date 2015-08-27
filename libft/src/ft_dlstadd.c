/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:04:30 by avallete          #+#    #+#             */
/*   Updated: 2015/05/29 20:16:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void                ft_dlstadd(t_dlst **lst, t_dlst *new)
{
    t_dlst *begin;

    begin = *lst;
    new->next = begin;
    *lst = new;
    new->back = NULL;
}
