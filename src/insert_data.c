/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:18:19 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 13:07:10 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ltree_insert_data(t_ltree **tree,\
		t_llstat data, int (*f)(t_llstat, t_llstat))
{
	t_ltree *root;

	if (*tree)
	{
		root = *tree;
		if ((f(root->infos, data)) < 0)
		{
			if (root->left)
				ltree_insert_data(&root->left, data, f);
			else
				root->left = create_node_stat(data);
		}
		else
		{
			if (root->right)
				ltree_insert_data(&root->right, data, f);
			else
				root->right = create_node_stat(data);
		}
	}
	else
		*tree = create_node_stat(data);
}
