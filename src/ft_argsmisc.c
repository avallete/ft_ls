/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsmisc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:35:12 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 15:36:39 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			check_slash(char *str)
{
	size_t i;

	if (str)
	{
		i = ft_strlen(str) - 1;
		if (str[i] == '/')
			return (1);
		else
			return (0);
	}
	return (0);
}

int			is_hide(char *pathname)
{
	int			i;

	i = ft_strlen(pathname);
	if (pathname)
	{
		while (pathname[i] != '/')
		{
			if (pathname[i] == '.' && pathname[i - 1] == '/')
				return (1);
			i--;
		}
	}
	return (0);
}

int			verify_argv(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i]) || argv[i][0] == '\0')
		{
			errno = ENOENT;
			print_error("fts_open");
			return (0);
		}
		i++;
	}
	return (1);
}

int			test_linkdest(t_llstat infos)
{
	struct stat *stats;

	if (infos.filetype == 10)
	{
		if ((stats = (struct stat*)malloc(sizeof(struct stat))))
		{
			if (stat(infos.pathname, stats) != -1)
			{
				if (take_typefile(stats->st_mode) == 4)
				{
					free(stats);
					stats = NULL;
					return (1);
				}
			}
			if (stats)
			{
				free(stats);
				stats = NULL;
			}
		}
	}
	return (0);
}
