/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 10:18:19 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 12:59:55 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ltree_delete(t_ltree **tree)
{
	if (*tree)
	{
		if ((*tree)->right)
			ltree_delete(&(*tree)->right);
		if ((*tree)->left)
			ltree_delete(&(*tree)->left);
		free((*tree));
	}
}

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
