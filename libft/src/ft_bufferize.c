/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 11:08:59 by avallete          #+#    #+#             */
/*   Updated: 2015/08/28 20:02:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bufferize.h"

void    flush_buf(int fd, char *buf, int *len)
{
    write(fd, buf, *len);
    buf[0] = 0;
    *len = 0;
}

int     ft_bufferize(int fd, char *str, bool flush)
{
    static char    buf[BUFFERIZE_SIZE + 1] = {'\0'};
    static int     place = 0;
    int            len;

    len = ft_strlen(str);
    if (len > 0)
    {
        if (place + len > BUFFERIZE_SIZE)
        {
            while (place + len >= BUFFERIZE_SIZE)
            {
                ft_strncpy(buf + place, str, (BUFFERIZE_SIZE - place));
                len -= (BUFFERIZE_SIZE - place);
                str += (BUFFERIZE_SIZE - place);
                place = BUFFERIZE_SIZE;
                flush_buf(fd, buf, &place);
            }
        }
        ft_strncpy(buf + place, str, len);
        place += len;
    }
    if (flush == true)
        flush_buf(fd, buf, &place);
    return (place);
}