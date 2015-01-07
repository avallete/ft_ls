/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:05:17 by avallete          #+#    #+#             */
/*   Updated: 2015/01/05 14:05:31 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		ft_putsterr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(2, &str[i++], 1);
}

void		ft_putcerr(char c)
{
	write(2, &c, 1);
}

void		print_error(char *filename)
{
	if (filename)
	{
		ft_putsterr("ls: ");
		perror(filename);
	}
}
