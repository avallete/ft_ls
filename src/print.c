/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:03:13 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 12:57:26 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ltree_print(t_ltree *root, size_t *infos, char *options)
{
	if (root)
	{
		if (FIRST(options[3], root))
			ltree_print(FIRST(options[3], root), infos, options);
		options[0] ? print_lsl(&root->infos, infos, options) :\
			print_ls(&root->infos, options);
		if (LAST(options[3], root))
			ltree_print(LAST(options[3], root), infos, options);
	}
}
