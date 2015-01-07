/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 16:14:51 by avallete          #+#    #+#             */
/*   Updated: 2015/01/06 15:43:50 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_arg(char *c, char e)
{
	if (e != 'l' && e != 't' && e != 'a' && e != 'r' && e != 'R' && e != '1'\
		&& e != 'A' && e != 'u' && e != 'U' && e != 'S' && e != 'c' && e != 'g')
	{
		ft_putsterr("ls : illegal option -- ");
		ft_putcerr(e);
		ft_putcerr('\n');
		ft_putsterr("usage : ls [-ltarR1AuUScg] [file ...]\n");
		return (-1);
	}
	e == '1' ? (c[0] = 0) : (c[0] += 0);
	e == 'u' ? (c[8] = 1), \
	(c[9] = 0) : (c[8] += 0);
	e == 'c' ? (c[8] = 2), \
	(c[9] = 0) : (c[8] += 0);
	e == 'U' ? (c[9] = 1) : (c[9] += 0);
	e == 'S' ? (c[10] = 1), \
	(c[1] = 0) : (c[10] += 0);
	e == 'l' ? (c[0] = 1) : (c[0] += 0);
	e == 'g' ? (c[0] = 2) : (c[0] += 0);
	e == 't' ? (c[1] = 1) : (c[1] += 0);
	e == 'a' ? (c[2] = 1) : (c[2] += 0);
	e == 'A' ? (c[7] = 1) : (c[7] += 0);
	e == 'r' ? (c[3] = 1) : (c[3] += 0);
	e == 'R' ? (c[5] = 1) : (c[5] += 0);
	return (0);
}

void		print_files_args(t_ltree *args, size_t *infos, char *options)
{
	if (args)
	{
		if (FIRST(options[3], args))
			print_files_args(FIRST(options[3], args), infos, options);
		if (args->infos.filetype != 4 && (!(test_linkdest(args->infos))))
		{
			options[0] ? print_lsl(&args->infos, infos, options) :\
				print_ls(&args->infos, options);
			options[6] = 1;
		}
		if (LAST(options[3], args))
			print_files_args(LAST(options[3], args), infos, options);
	}
}

void		print_dir_args(t_ltree *args, char *options)
{
	if (args)
	{
		if (FIRST(options[3], args))
			print_dir_args(FIRST(options[3], args), options);
		if (args->infos.filetype == 4 || ((test_linkdest(args->infos))))
		{
			print_dir(args->infos.filename, options);
			options[6] = 1;
			set_up(args->infos.pathname, options);
		}
		if (LAST(options[3], args))
			print_dir_args(LAST(options[3], args), options);
	}
}

void		argument_sort(char **argv, int *tab, char *choice)
{
	t_ltree			*args;
	static size_t	keep_infos[6] = {0};

	args = NULL;
	while (tab[0] < tab[1])
	{
		ls_file(&args, argv[tab[0]], choice, keep_infos);
		tab[0]++;
	}
	if (args)
	{
		print_files_args(args, keep_infos, choice);
		print_dir_args(args, choice);
	}
}

int			ft_arguments(int argc, char **argv, char *choice)
{
	int				i;
	unsigned int	j;
	size_t			l;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		if ((ft_strcmp((argv[i]), "--")) == 0)
			return (i + 1);
		j = 1;
		l = ft_strlen(argv[i]);
		while (j < l)
		{
			if ((ft_arg(choice, argv[i][j])))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}
