/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:12:51 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 15:19:54 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		initialize_infos(size_t *infos)
{
	int i;

	i = 0;
	while (i++ < 6)
		infos[i] = 0;
	infos[0] = 1;
}

void		ft_printls(char *filename, char hide)
{
	if ((hide))
		ft_bufferize(1, filename, false);
	else
	{
		if (filename[0] != '.')
			ft_bufferize(1, filename, false);
	}
}

void		arg_is_dir(t_ltree *args, int *dir, int *file)
{
	if (args)
	{
		if (args->right)
			arg_is_dir(args->right, dir, file);
		if (args->left)
			arg_is_dir(args->left, dir, file);
	}
	if (args->infos.filetype == 4)
		*dir = 1;
	if (args->infos.filetype != 4)
		*file = 1;
}

char		*filename(char *pathname)
{
	int i;

	i = ft_strlen(pathname);
	while (i != 0 && pathname[i] != '/')
		i--;
	if (i != 0)
		i++;
	return (pathname + i);
}
