/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:44:53 by avallete          #+#    #+#             */
/*   Updated: 2015/08/27 16:22:31 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	args_one(char *choice, char *pathname)
{
	t_ltree			*tree;
	static size_t	keep_infos[6] = {0};

	tree = NULL;
	ls_file(&tree, pathname, choice, keep_infos);
	if (tree)
	{
		if (tree->infos.filetype != 10 || ((test_linkdest(tree->infos)) &&\
					(!(choice[0]))) || (!(test_linkdest(tree->infos))))
			set_up(pathname, choice);
		else if ((test_linkdest(tree->infos)))
			choice[0] ? print_lsl(&tree->infos, keep_infos, choice) :\
				print_ls(&tree->infos, choice);
		ltree_delete(&tree);
	}
}

void	set_up_argv(int argc, char **argv, int i, char *choice)
{
	int		tab[2];

	tab[0] = i;
	tab[1] = argc;
	if (argc > i + 1)
		argument_sort(argv, tab, choice);
	else
		args_one(choice, argv[i]);
}

int		main(int argc, char **argv)
{
	int		i;
	char	choice[11];

	choice[6] = 0;
	if (verify_argv(argc, argv))
	{
		ft_bzero(choice, 11);
		if (argc == 1)
			set_up(".", choice);
		if (argc > 1)
		{
			i = ft_arguments(argc, argv, choice);
			if (i == -1)
				return (0);
			if (i == argc)
				set_up((char*)".", choice);
			else
				set_up_argv(argc, argv, i, choice);
		}
	}
	return (0);
}
