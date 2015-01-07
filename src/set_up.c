/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:41:41 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 11:28:28 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	set_up(char *argv, char *choice)
{
	t_ltree *tree;
	size_t	*infos;

	tree = NULL;
	infos = NULL;
	infos = ls_read_stat(&tree, argv, choice);
	ltree_print(tree, infos, choice);
	choice[6] = 1;
	initialize_infos(infos);
	if (choice[5])
		call_setup(tree, choice);
}

void	print_dir(char *name, char *choice)
{
	if (choice[6])
		ft_putchar('\n');
	choice[6] = 1;
	ft_putstr(name);
	ft_putendl(":");
}

void	call_setup(t_ltree *args, char *choice)
{
	if (args)
	{
		if (FIRST(choice[3], args))
			call_setup(FIRST(choice[3], args), choice);
		if (args->infos.filetype == 4)
		{
			if (ft_strcmp(args->infos.filename, ".") &&\
					ft_strcmp(args->infos.filename, ".."))
			{
				if (choice[2] || ((!(choice[2]) &&\
						args->infos.filename[0] != '.')))
				{
					choice[5] ? print_dir(args->infos.pathname, choice)\
						: print_dir(args->infos.filename, choice);
					set_up(args->infos.pathname, choice);
				}
			}
		}
		if (LAST(choice[3], args))
			call_setup(LAST(choice[3], args), choice);
	}
}
